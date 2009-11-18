require 'test/unit'

begin
  require 'dtrace'
rescue LoadError
end

if respond_to?(:dtrace)
  class TestDtrace < Test::Unit::TestCase
    def test_trace
      assert_raises ArgumentError do
        dtrace("test")
      end
    end  
  end
end