require 'test/unit'
require 'continuation'

class TestHash < Test::Unit::TestCase

  def test_hash
    x = {1=>2, 2=>4, 3=>6}
    y = {1=>2, 2=>4, 3=>6} # y = {1, 2, 2, 4, 3, 6} # 1.9 doesn't support

    assert_equal(2, x[1])

    assert(begin
         for k,v in y
           raise if k*2 != v
         end
         true
       rescue
         false
       end)

    assert_equal(3, x.length)
    assert(x.has_key?(1))
    assert(x.has_value?(4))
    assert_equal([4,6], x.values_at(2,3))
    assert_equal({1=>2, 2=>4, 3=>6}, x)

    z = y.keys.join(":")
    assert_equal("1:2:3", z)

    z = y.values.join(":")
    assert_equal("2:4:6", z)
    assert_equal(x, y)

    y.shift
    assert_equal(2, y.length)

    z = [1,2]
    y[z] = 256
    assert_equal(256, y[z])

    x = Hash.new(0)
    x[1] = 1
    assert_equal(1, x[1])
    assert_equal(0, x[2])

    x = Hash.new([])
    assert_equal([], x[22])
    assert_same(x[22], x[22])

    x = Hash.new{[]}
    assert_equal([], x[22])
    assert_not_same(x[22], x[22])

    x = Hash.new{|h,k| z = k; h[k] = k*2}
    z = 0
    assert_equal(44, x[22])
    assert_equal(22, z)
    z = 0
    assert_equal(44, x[22])
    assert_equal(0, z)
    x.default = 5
    assert_equal(5, x[23])

    x = Hash.new
    def x.default(k)
      $z = k
      self[k] = k*2
    end
    $z = 0
    assert_equal(44, x[22])
    assert_equal(22, $z)
    $z = 0
    assert_equal(44, x[22])
    assert_equal(0, $z)
  end

  # From rubicon

  def setup
    @cls = Hash
    @h = @cls[
      1 => 'one', 2 => 'two', 3 => 'three',
      self => 'self', true => 'true', nil => 'nil',
      'nil' => nil
    ]
    @verbose = $VERBOSE
    $VERBOSE = nil
  end

  def teardown
    $VERBOSE = @verbose
  end

  def test_s_AREF
    h = @cls["a" => 100, "b" => 200]
    assert_equal(100, h['a'])
    assert_equal(200, h['b'])
    assert_nil(h['c'])

    h = @cls.[]("a" => 100, "b" => 200)
    assert_equal(100, h['a'])
    assert_equal(200, h['b'])
    assert_nil(h['c'])
  end

  def test_s_new
    h = @cls.new
    assert_instance_of(@cls, h)
    assert_nil(h.default)
    assert_nil(h['spurious'])

    h = @cls.new('default')
    assert_instance_of(@cls, h)
    assert_equal('default', h.default)
    assert_equal('default', h['spurious'])

  end

  def test_AREF # '[]'
    t = Time.now
    h = @cls[
      1 => 'one', 2 => 'two', 3 => 'three',
      self => 'self', t => 'time', nil => 'nil',
      'nil' => nil
    ]

    assert_equal('one',   h[1])
    assert_equal('two',   h[2])
    assert_equal('three', h[3])
    assert_equal('self',  h[self])
    assert_equal('time',  h[t])
    assert_equal('nil',   h[nil])
    assert_equal(nil,     h['nil'])
    assert_equal(nil,     h['koala'])

    h1 = h.dup
    h1.default = :default

    assert_equal('one',    h1[1])
    assert_equal('two',    h1[2])
    assert_equal('three',  h1[3])
    assert_equal('self',   h1[self])
    assert_equal('time',   h1[t])
    assert_equal('nil',    h1[nil])
    assert_equal(nil,      h1['nil'])
    assert_equal(:default, h1['koala'])


  end

  def test_ASET # '[]='
    t = Time.now
    h = @cls.new
    h[1]     = 'one'
    h[2]     = 'two'
    h[3]     = 'three'
    h[self]  = 'self'
    h[t]     = 'time'
    h[nil]   = 'nil'
    h['nil'] = nil
    assert_equal('one',   h[1])
    assert_equal('two',   h[2])
    assert_equal('three', h[3])
    assert_equal('self',  h[self])
    assert_equal('time',  h[t])
    assert_equal('nil',   h[nil])
    assert_equal(nil,     h['nil'])
    assert_equal(nil,     h['koala'])

    h[1] = 1
    h[nil] = 99
    h['nil'] = nil
    z = [1,2]
    h[z] = 256
    assert_equal(1,       h[1])
    assert_equal('two',   h[2])
    assert_equal('three', h[3])
    assert_equal('self',  h[self])
    assert_equal('time',  h[t])
    assert_equal(99,      h[nil])
    assert_equal(nil,     h['nil'])
    assert_equal(nil,     h['koala'])
    assert_equal(256,     h[z])
  end

  def test_EQUAL # '=='
    h1 = @cls[ "a" => 1, "c" => 2 ]
    h2 = @cls[ "a" => 1, "c" => 2, 7 => 35 ]
    h3 = @cls[ "a" => 1, "c" => 2, 7 => 35 ]
    h4 = @cls[ ]
    assert(h1 == h1)
    assert(h2 == h2)
    assert(h3 == h3)
    assert(h4 == h4)
    assert(!(h1 == h2))
    assert(h2 == h3)
    assert(!(h3 == h4))
  end

  def test_clear
    assert(@h.size > 0)
    @h.clear
    assert_equal(0, @h.size)
    assert_nil(@h[1])
  end

  def test_clone
    for taint in [ false, true ]
      for untrust in [ false, true ]
        for frozen in [ false, true ]
          a = @h.clone
          a.taint  if taint
          a.untrust if untrust
          a.freeze if frozen
          b = a.clone

          assert_equal(a, b)
          assert(a.__id__ != b.__id__)
          assert_equal(a.frozen?, b.frozen?)
          assert_equal(a.untrusted?, b.untrusted?)
          assert_equal(a.tainted?, b.tainted?)
        end
      end
    end
  end

  def test_default
    assert_nil(@h.default)
    h = @cls.new(:xyzzy)
    assert_equal(:xyzzy, h.default)
  end

  def test_default=
    assert_nil(@h.default)
    @h.default = :xyzzy
    assert_equal(:xyzzy, @h.default)
  end

  def test_delete
    h1 = @cls[ 1 => 'one', 2 => 'two', true => 'true' ]
    h2 = @cls[ 1 => 'one', 2 => 'two' ]
    h3 = @cls[ 2 => 'two' ]

    assert_equal('true', h1.delete(true))
    assert_equal(h2, h1)

    assert_equal('one', h1.delete(1))
    assert_equal(h3, h1)

    assert_equal('two', h1.delete(2))
    assert_equal(@cls[], h1)

    assert_nil(h1.delete(99))
    assert_equal(@cls[], h1)

    assert_equal('default 99', h1.delete(99) {|i| "default #{i}" })
  end

  def test_delete_if
    base = @cls[ 1 => 'one', 2 => false, true => 'true', 'cat' => 99 ]
    h1   = @cls[ 1 => 'one', 2 => false, true => 'true' ]
    h2   = @cls[ 2 => false, 'cat' => 99 ]
    h3   = @cls[ 2 => false ]

    h = base.dup
    assert_equal(h, h.delete_if { false })
    assert_equal(@cls[], h.delete_if { true })

    h = base.dup
    assert_equal(h1, h.delete_if {|k,v| k.instance_of?(String) })
    assert_equal(h1, h)

    h = base.dup
    assert_equal(h2, h.delete_if {|k,v| v.instance_of?(String) })
    assert_equal(h2, h)

    h = base.dup
    assert_equal(h3, h.delete_if {|k,v| v })
    assert_equal(h3, h)

    h = base.dup
    n = 0
    h.delete_if {|*a|
      n += 1
      assert_equal(2, a.size)
      assert_equal(base[a[0]], a[1])
      h.shift
      true
    }
    assert_equal(base.size, n)
  end

  def test_dup
    for taint in [ false, true ]
      for untrust in [ false, true ]
        for frozen in [ false, true ]
          a = @h.dup
          a.taint  if taint
          a.freeze if frozen
          b = a.dup

          assert_equal(a, b)
          assert(a.__id__ != b.__id__)
          assert_equal(false, b.frozen?)
          assert_equal(a.tainted?, b.tainted?)
          assert_equal(a.untrusted?, b.untrusted?)
        end
      end
    end
  end

  def test_each
    count = 0
    @cls[].each { |k, v| count + 1 }
    assert_equal(0, count)

    h = @h
    h.each do |k, v|
      assert_equal(v, h.delete(k))
    end
    assert_equal(@cls[], h)
  end

  def test_each_key
    count = 0
    @cls[].each_key { |k| count + 1 }
    assert_equal(0, count)

    h = @h
    h.each_key do |k|
      h.delete(k)
    end
    assert_equal(@cls[], h)
  end

  def test_each_pair
    count = 0
    @cls[].each_pair { |k, v| count + 1 }
    assert_equal(0, count)

    h = @h
    h.each_pair do |k, v|
      assert_equal(v, h.delete(k))
    end
    assert_equal(@cls[], h)
  end

  def test_each_value
    res = []
    @cls[].each_value { |v| res << v }
    assert_equal(0, [].length)

    @h.each_value { |v| res << v }
    assert_equal(0, [].length)

    expected = []
    @h.each { |k, v| expected << v }

    assert_equal([], expected - res)
    assert_equal([], res - expected)
  end

  def test_empty?
    assert(@cls[].empty?)
    assert(!@h.empty?)
  end

  def test_fetch
    assert_raise(KeyError) { @cls[].fetch(1) }
    assert_raise(KeyError) { @h.fetch('gumby') }
    assert_equal('gumbygumby', @h.fetch('gumby') {|k| k * 2 })
    assert_equal('pokey', @h.fetch('gumby', 'pokey'))

    assert_equal('one', @h.fetch(1))
    assert_equal(nil, @h.fetch('nil'))
    assert_equal('nil', @h.fetch(nil))
  end

  def test_key?
    assert(!@cls[].key?(1))
    assert(!@cls[].key?(nil))
    assert(@h.key?(nil))
    assert(@h.key?(1))
    assert(!@h.key?('gumby'))
  end

  def test_value?
    assert(!@cls[].value?(1))
    assert(!@cls[].value?(nil))
    assert(@h.value?('one'))
    assert(@h.value?(nil))
    assert(!@h.value?('gumby'))
  end

  def test_include?
    assert(!@cls[].include?(1))
    assert(!@cls[].include?(nil))
    assert(@h.include?(nil))
    assert(@h.include?(1))
    assert(!@h.include?('gumby'))
  end

  def test_key
    assert_equal(1,     @h.key('one'))
    assert_equal(nil,   @h.key('nil'))
    assert_equal('nil', @h.key(nil))

    assert_equal(nil,   @h.key('gumby'))
    assert_equal(nil,   @cls[].key('gumby'))
  end

  def test_values_at
    res = @h.values_at('dog', 'cat', 'horse')
    assert(res.length == 3)
    assert_equal([nil, nil, nil], res)

    res = @h.values_at
    assert(res.length == 0)

    res = @h.values_at(3, 2, 1, nil)
    assert_equal 4, res.length
    assert_equal %w( three two one nil ), res

    res = @h.values_at(3, 99, 1, nil)
    assert_equal 4, res.length
    assert_equal ['three', nil, 'one', 'nil'], res
  end


  def test_invert
    h = @h.invert
    assert_equal(1, h['one'])
    assert_equal(true, h['true'])
    assert_equal(nil,  h['nil'])

    h.each do |k, v|
      assert(@h.key?(v))    # not true in general, but works here
    end

    h = @cls[ 'a' => 1, 'b' => 2, 'c' => 1].invert
    assert_equal(2, h.length)
    assert(h[1] == 'a' || h[1] == 'c')
    assert_equal('b', h[2])
  end

  def test_key?
    assert(!@cls[].key?(1))
    assert(!@cls[].key?(nil))
    assert(@h.key?(nil))
    assert(@h.key?(1))
    assert(!@h.key?('gumby'))
  end

  def test_keys
    assert_equal([], @cls[].keys)

    keys = @h.keys
    expected = []
    @h.each { |k, v| expected << k }
    assert_equal([], keys - expected)
    assert_equal([], expected - keys)
  end

  def test_length
    assert_equal(0, @cls[].length)
    assert_equal(7, @h.length)
  end

  def test_member?
    assert(!@cls[].member?(1))
    assert(!@cls[].member?(nil))
    assert(@h.member?(nil))
    assert(@h.member?(1))
    assert(!@h.member?('gumby'))
  end

  def test_rehash
    a = [ "a", "b" ]
    c = [ "c", "d" ]
    h = @cls[ a => 100, c => 300 ]
    assert_equal(100, h[a])
    a[0] = "z"
    assert_nil(h[a])
    h.rehash
    assert_equal(100, h[a])
  end

  def test_reject
    base = @cls[ 1 => 'one', 2 => false, true => 'true', 'cat' => 99 ]
    h1   = @cls[ 1 => 'one', 2 => false, true => 'true' ]
    h2   = @cls[ 2 => false, 'cat' => 99 ]
    h3   = @cls[ 2 => false ]

    h = base.dup
    assert_equal(h, h.reject { false })
    assert_equal(@cls[], h.reject { true })

    h = base.dup
    assert_equal(h1, h.reject {|k,v| k.instance_of?(String) })

    assert_equal(h2, h.reject {|k,v| v.instance_of?(String) })

    assert_equal(h3, h.reject {|k,v| v })
    assert_equal(base, h)
  end

  def test_reject!
    base = @cls[ 1 => 'one', 2 => false, true => 'true', 'cat' => 99 ]
    h1   = @cls[ 1 => 'one', 2 => false, true => 'true' ]
    h2   = @cls[ 2 => false, 'cat' => 99 ]
    h3   = @cls[ 2 => false ]

    h = base.dup
    assert_equal(nil, h.reject! { false })
    assert_equal(@cls[],  h.reject! { true })

    h = base.dup
    assert_equal(h1, h.reject! {|k,v| k.instance_of?(String) })
    assert_equal(h1, h)

    h = base.dup
    assert_equal(h2, h.reject! {|k,v| v.instance_of?(String) })
    assert_equal(h2, h)

    h = base.dup
    assert_equal(h3, h.reject! {|k,v| v })
    assert_equal(h3, h)
  end

  def test_replace
    h = @cls[ 1 => 2, 3 => 4 ]
    h1 = h.replace(@cls[ 9 => 8, 7 => 6 ])
    assert_equal(h, h1)
    assert_equal(8, h[9])
    assert_equal(6, h[7])
    assert_nil(h[1])
    assert_nil(h[2])
  end

  def test_shift
    h = @h.dup

    @h.length.times {
      k, v = h.shift
      assert(@h.key?(k))
      assert_equal(@h[k], v)
    }

    assert_equal(0, h.length)
  end

  def test_size
    assert_equal(0, @cls[].length)
    assert_equal(7, @h.length)
  end

  def test_sort
    h = @cls[].sort
    assert_equal([], h)

    h = @cls[ 1 => 1, 2 => 1 ].sort
    assert_equal([[1,1], [2,1]], h)

    h = @cls[ 'cat' => 'feline', 'ass' => 'asinine', 'bee' => 'beeline' ]
    h1 = h.sort
    assert_equal([ %w(ass asinine), %w(bee beeline), %w(cat feline)], h1)
  end

  def test_store
    t = Time.now
    h = @cls.new
    h.store(1, 'one')
    h.store(2, 'two')
    h.store(3, 'three')
    h.store(self, 'self')
    h.store(t,  'time')
    h.store(nil, 'nil')
    h.store('nil', nil)
    assert_equal('one',   h[1])
    assert_equal('two',   h[2])
    assert_equal('three', h[3])
    assert_equal('self',  h[self])
    assert_equal('time',  h[t])
    assert_equal('nil',   h[nil])
    assert_equal(nil,     h['nil'])
    assert_equal(nil,     h['koala'])

    h.store(1, 1)
    h.store(nil,  99)
    h.store('nil', nil)
    assert_equal(1,       h[1])
    assert_equal('two',   h[2])
    assert_equal('three', h[3])
    assert_equal('self',  h[self])
    assert_equal('time',  h[t])
    assert_equal(99,      h[nil])
    assert_equal(nil,     h['nil'])
    assert_equal(nil,     h['koala'])
  end

  def test_to_a
    assert_equal([], @cls[].to_a)
    assert_equal([[1,2]], @cls[ 1=>2 ].to_a)
    a = @cls[ 1=>2, 3=>4, 5=>6 ].to_a
    assert_equal([1,2], a.delete([1,2]))
    assert_equal([3,4], a.delete([3,4]))
    assert_equal([5,6], a.delete([5,6]))
    assert_equal(0, a.length)

    h = @cls[ 1=>2, 3=>4, 5=>6 ]
    h.taint
    h.untrust
    a = h.to_a
    assert_equal(true, a.tainted?)
    assert_equal(true, a.untrusted?)
  end

  def test_to_hash
    h = @h.to_hash
    assert_equal(@h, h)
  end

  def test_to_s
    h = @cls[ 1 => 2, "cat" => "dog", 1.5 => :fred ]
    assert_equal(h.inspect, h.to_s)
    $, = ":"
    assert_equal(h.inspect, h.to_s)
    h = @cls[]
    assert_equal(h.inspect, h.to_s)
  ensure
    $, = nil
  end

  def test_update
    h1 = @cls[ 1 => 2, 2 => 3, 3 => 4 ]
    h2 = @cls[ 2 => 'two', 4 => 'four' ]

    ha = @cls[ 1 => 2, 2 => 'two', 3 => 4, 4 => 'four' ]
    hb = @cls[ 1 => 2, 2 => 3, 3 => 4, 4 => 'four' ]

    assert_equal(ha, h1.update(h2))
    assert_equal(ha, h1)

    h1 = @cls[ 1 => 2, 2 => 3, 3 => 4 ]
    h2 = @cls[ 2 => 'two', 4 => 'four' ]

    assert_equal(hb, h2.update(h1))
    assert_equal(hb, h2)
  end

  def test_value?
    assert(!@cls[].value?(1))
    assert(!@cls[].value?(nil))
    assert(@h.value?(nil))
    assert(@h.value?('one'))
    assert(!@h.value?('gumby'))
  end

  def test_values
    assert_equal([], @cls[].values)

    vals = @h.values
    expected = []
    @h.each { |k, v| expected << v }
    assert_equal([], vals - expected)
    assert_equal([], expected - vals)
  end

  def test_security_check
    h = {}
    assert_raise(SecurityError) do
      Thread.new do
        $SAFE = 4
        h[1] = 1
      end.join
    end
  end

  def test_intialize_wrong_arguments
    assert_raise(ArgumentError) do
      Hash.new(0) { }
    end
  end

  def test_create
    assert_equal({1=>2, 3=>4}, Hash[[[1,2],[3,4]]])
    assert_raise(ArgumentError) { Hash[0, 1, 2] }
    assert_equal({1=>2, 3=>4}, Hash[1,2,3,4])
    o = Object.new
    def o.to_hash() {1=>2} end
    assert_equal({1=>2}, Hash[o], "[ruby-dev:34555]")
  end

  def test_rehash2
    h = {1 => 2, 3 => 4}
    assert_equal(h.dup, h.rehash)
    assert_raise(RuntimeError) { h.each { h.rehash } }
    assert_equal({}, {}.rehash)
  end

  def test_fetch2
    assert_equal(:bar, @h.fetch(0, :foo) { :bar })
  end

  def test_default_proc
    h = Hash.new {|h, k| h + k + "baz" }
    assert_equal("foobarbaz", h.default_proc.call("foo", "bar"))
    h = {}
    assert_nil(h.default_proc)
  end

  def test_shift2
    h = Hash.new {|h, k| :foo }
    h[1] = 2
    assert_equal([1, 2], h.shift)
    assert_equal(:foo, h.shift)
    assert_equal(:foo, h.shift)

    h = Hash.new(:foo)
    h[1] = 2
    assert_equal([1, 2], h.shift)
    assert_equal(:foo, h.shift)
    assert_equal(:foo, h.shift)

    h = {1=>2}
    h.each { assert_equal([1, 2], h.shift) }
  end

  def test_reject_bang2
    assert_equal({1=>2}, {1=>2,3=>4}.reject! {|k, v| k + v == 7 })
    assert_nil({1=>2,3=>4}.reject! {|k, v| k == 5 })
    assert_nil({}.reject! { })
  end

  def test_select
    assert_equal({3=>4,5=>6}, {1=>2,3=>4,5=>6}.select {|k, v| k + v >= 7 })
  end

  def test_clear2
    assert_equal({}, {1=>2,3=>4,5=>6}.clear)
    h = {1=>2,3=>4,5=>6}
    h.each { h.clear }
    assert_equal({}, h)
  end

  def test_replace2
    h1 = Hash.new { :foo }
    h2 = {}
    h2.replace h1
    assert_equal(:foo, h2[0])
  end

  def test_size2
    assert_equal(0, {}.size)
  end

  def test_equal2
    assert({} != 0)
    o = Object.new
    def o.to_hash; {}; end
    def o.==(x); true; end
    assert({} == o)
    def o.==(x); false; end
    assert({} != o)

    h1 = {1=>2}; h2 = {3=>4}
    assert(h1 != h2)
    h1 = {1=>2}; h2 = {1=>4}
    assert(h1 != h2)
  end

  def test_eql
    assert(!({}.eql?(0)))
    o = Object.new
    def o.to_hash; {}; end
    def o.eql?(x); true; end
    assert({}.eql?(o))
    def o.eql?(x); false; end
    assert(!({}.eql?(o)))
  end

  def test_hash2
    assert_kind_of(Integer, {}.hash)
  end

  def test_update2
    h1 = {1=>2, 3=>4}
    h2 = {1=>3, 5=>7}
    h1.update(h2) {|k, v1, v2| k + v1 + v2 }
    assert_equal({1=>6, 3=>4, 5=>7}, h1)
  end

  def test_merge
    h1 = {1=>2, 3=>4}
    h2 = {1=>3, 5=>7}
    assert_equal({1=>3, 3=>4, 5=>7}, h1.merge(h2))
    assert_equal({1=>6, 3=>4, 5=>7}, h1.merge(h2) {|k, v1, v2| k + v1 + v2 })
  end

  def test_assoc
    assert_equal([3,4], {1=>2, 3=>4, 5=>6}.assoc(3))
    assert_nil({1=>2, 3=>4, 5=>6}.assoc(4))
  end

  def test_rassoc
    assert_equal([3,4], {1=>2, 3=>4, 5=>6}.rassoc(4))
    assert_nil({1=>2, 3=>4, 5=>6}.rassoc(3))
  end

  def test_flatten
    assert_equal([[1], [2]], {[1] => [2]}.flatten)
  end

  def test_callcc
    h = {1=>2}
    c = nil
    f = false
    h.each { callcc {|c2| c = c2 } }
    unless f
      f = true
      c.call
    end
    assert_raise(RuntimeError) { h.each { h.rehash } }

    h = {1=>2}
    c = nil
    assert_raise(RuntimeError) do
      h.each { callcc {|c2| c = c2 } }
      h.clear
      c.call
    end
  end

  def test_compare_by_identity
    a = "foo"
    assert(!{}.compare_by_identity?)
    h = { a => "bar" }
    assert(!h.compare_by_identity?)
    h.compare_by_identity
    assert(h.compare_by_identity?)
    #assert_equal("bar", h[a])
    assert_nil(h["foo"])
  end

  class ObjWithHash
    def initialize(value, hash)
      @value = value
      @hash = hash
    end
    attr_reader :value, :hash

    def eql?(other)
      @value == other.value
    end
  end

  def test_hash_hash
    assert_equal({0=>2,11=>1}.hash, {11=>1,0=>2}.hash)
    o1 = ObjWithHash.new(0,1)
    o2 = ObjWithHash.new(11,1)
    assert_equal({o1=>1,o2=>2}.hash, {o2=>2,o1=>1}.hash)
  end

  def test_hash_bignum_hash
    x = 2<<(32-3)-1
    assert_equal({x=>1}.hash, {x=>1}.hash)
    x = 2<<(64-3)-1
    assert_equal({x=>1}.hash, {x=>1}.hash)

    o = Object.new
    def o.hash; 2<<100; end
    assert_equal({x=>1}.hash, {x=>1}.hash)
  end
end

class HashToStrHash < Test::Unit::TestCase
  def test_strhash
    hash = { 'a' => 1, 'b' => 2 }
    assert_instance_of StrHash, hash.strhash
    assert_equal %w(a b), hash.keys
    assert_equal [1,2], hash.values
  end  
end

class TestStrHash < Test::Unit::TestCase
  def setup
    @strings = { 'a' => 1, 'b' => 2 }.strhash
    @symbols = { :a  => 1, :b  => 2 }.strhash
    @mixed   = { :a  => 1, 'b' => 2 }.strhash
    @fixnums = {  0  => 1,  1  => 2 }.strhash
  end

  def test_inherits_hash
    assert_equal Hash, StrHash.superclass
  end

  def test_strhash
    assert_equal @strings.object_id, @strings.strhash.object_id
    assert_instance_of StrHash, { 'a' => 1, 'b' => 2 }.strhash
  end
  
  def test_initialize
    strhash = StrHash.new({ 'a' => 1, 'b' => 2 })
    assert_equal 1, strhash[:a] 
    strhash = StrHash.new
    strhash[:a] = 'a'
    assert_equal 'a', strhash[:a]
  end

  def test_set
    array = [{ 'a' => 1, 'b' => 2 }, [:a,:b,:c]]
    @strings[:array] = array
    assert_instance_of StrHash, @strings[:array].shift
    assert_instance_of Array, @strings[:array] = array    
    @strings[:hash] = { 'a' => 1, 'b' => 2 }
    assert_instance_of StrHash, @strings[:hash]
  end
  
  def test_dup
    assert_equal @strings, @strings.dup
    assert_equal @mixed, @mixed.dup
    assert_not_equal @mixed.object_id, @mixed.dup.object_id
  end

  def test_keys
    assert_equal ["a", "b"], @strings.keys
    assert_equal [:a, :b], @symbols.keys
    assert_equal [:a, "b"], @mixed.keys
    assert_equal [0, 1], @fixnums.keys            
  end
  
  def test_values
    assert_equal [1, 2], @strings.values
    assert_equal [1, 2], @symbols.values
    assert_equal [1, 2], @mixed.values
    assert_equal [1, 2], @fixnums.values         
  end  
 
  def test_fetch
    assert_equal 1, @strings.fetch('a')
    assert_equal 1, @strings.fetch(:a.to_s)
    assert_equal 1, @strings.fetch(:a)
  end

  def test_key?
    assert @strings.key?(:a)
    assert @strings.include?('a')
    assert @mixed.has_key?('b')
  end
  
  def test_delete
    @strings.delete('a')
    assert !@strings.key?(:a)
  end

  def test_assorted
    hashes = { :@strings => @strings, :@symbols => @symbols, :@mixed => @mixed }
    method_map = { :'[]' => 1, :fetch => 1, :values_at => [1],
      :has_key? => true, :include? => true, :key? => true,
      :member? => true }

    hashes.each do |name, hash|
      method_map.sort_by { |m| m.to_s }.each do |meth, expected|
        assert_equal(expected, hash.__send__(meth, 'a'),
                     "Calling #{name}.#{meth} 'a'")
        assert_equal(expected, hash.__send__(meth, :a),
                     "Calling #{name}.#{meth} :a")
      end
    end

    assert_equal [1, 2], @strings.values_at('a', 'b')
    assert_equal [1, 2], @strings.values_at(:a, :b)
    assert_equal [1, 2], @symbols.values_at('a', 'b')
    assert_equal [1, 2], @symbols.values_at(:a, :b)
    assert_equal [1, 2], @mixed.values_at('a', 'b')
    assert_equal [1, 2], @mixed.values_at(:a, :b)
  end
  
  def test_reading
    hash = StrHash.new
    hash["a"] = 1
    hash["b"] = true
    hash["c"] = false
    hash["d"] = nil

    assert_equal 1, hash[:a]
    assert_equal true, hash[:b]
    assert_equal false, hash[:c]
    assert_equal nil, hash[:d]
    assert_equal nil, hash[:e]
  end  

  def test_reading_with_nonnil_default
    hash = StrHash.new(1)
    hash["a"] = 1
    hash["b"] = true
    hash["c"] = false
    hash["d"] = nil

    assert_equal 1, hash[:a]
    assert_equal true, hash[:b]
    assert_equal false, hash[:c]
    assert_equal nil, hash[:d]
    assert_equal 1, hash[:e]
  end
  
  def test_writing
    hash = StrHash.new
    hash[:a] = 1
    hash['b'] = 2
    hash[3] = 3

    assert_equal hash['a'], 1
    assert_equal hash['b'], 2
    assert_equal hash[:a], 1
    assert_equal hash[:b], 2
    assert_equal hash[3], 3
  end  

  def test_update
    hash = StrHash.new
    hash[:a] = 'a'
    hash['b'] = 'b'

    updated_with_strings = hash.update(@strings)
    updated_with_symbols = hash.update(@symbols)
    updated_with_mixed = hash.update(@mixed)

    assert_equal updated_with_strings[:a], 1
    assert_equal updated_with_strings['a'], 1
    assert_equal updated_with_strings['b'], 2

    assert_equal updated_with_symbols[:a], 1
    assert_equal updated_with_symbols['b'], 2
    assert_equal updated_with_symbols[:b], 2

    assert_equal updated_with_mixed[:a], 1
    assert_equal updated_with_mixed['b'], 2

    assert [updated_with_strings, updated_with_symbols, updated_with_mixed].all? { |h| h.keys.size == 2 }
  end  

  def test_merging
    hash = StrHash.new
    hash[:a] = 'failure'
    hash['b'] = 'failure'

    other = { 'a' => 1, :b => 2 }

    merged = hash.merge(other)

    assert_equal StrHash, merged.class
    assert_equal 1, merged[:a]
    assert_equal 2, merged['b']

    hash.update(other)

    assert_equal 1, hash[:a]
    assert_equal 2, hash['b']
  end  

  def test_deleting
    get_hash = proc{ StrHash[ :a => 'foo' ] }
    hash = get_hash.call
    assert_equal hash.delete(:a), 'foo'
    assert_equal hash.delete(:a), nil
    hash = get_hash.call
    assert_equal hash.delete('a'), 'foo'
    assert_equal hash.delete('a'), nil
  end  

  def test_to_hash
    assert_instance_of Hash, @strings.to_hash
    assert_equal %w(a b), @strings.to_hash.keys
    # Should convert to a Hash with String keys.
    assert_equal @strings, @mixed.strhash.to_hash

    # Should preserve the default value.
    mixed_with_default = @mixed.dup
    mixed_with_default.default = '1234'
    roundtrip = mixed_with_default.strhash.to_hash
    assert_equal @strings, roundtrip
    assert_equal '1234', roundtrip.default    
  end

  def test_hash_with_array_of_hashes
    hash = { "urls" => { "url" => [ { "address" => "1" }, { "address" => "2" } ] }}
    strhash = StrHash[hash]
    assert_equal "1", strhash[:urls][:url].first[:address]
  end

  def test_indifferent_subhashes
    h = {'user' => {'id' => 5}}.strhash
    ['user', :user].each {|user| [:id, 'id'].each {|id| assert_equal 5, h[user][id], "h[#{user.inspect}][#{id.inspect}] should be 5"}}

    h = {:user => {:id => 5}}.strhash
    ['user', :user].each {|user| [:id, 'id'].each {|id| assert_equal 5, h[user][id], "h[#{user.inspect}][#{id.inspect}] should be 5"}}
  end  

  def test_assorted_keys_not_stringified
    original = {Object.new => 2, 1 => 2, [] => true}
    indiff = original.strhash
    assert(!indiff.keys.any? {|k| k.kind_of? String}, "A key was converted to a string!")
  end

  def test_should_use_default_value_for_unknown_key
    strhash = StrHash.new(3)
    assert_equal 3, strhash[:new_key]
  end

  def test_should_use_default_value_if_no_key_is_supplied
    strhash = StrHash.new(3)
    assert_equal 3, strhash.default
  end

  def test_should_nil_if_no_default_value_is_supplied
    strhash = StrHash.new
    assert_nil strhash.default
  end

  def test_should_copy_the_default_value_when_converting_to_hash_with_indifferent_access
    hash = Hash.new(3)
    strhash = hash.strhash
    assert_equal 3, strhash.default
  end  
end