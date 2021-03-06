# Copyright (c) 2003, 2004 Jim Weirich, 2009 Eric Hodel
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

require_relative 'gemutilities'
require 'rubygems'
require 'rubygems/package_task'

class TestGemPackageTask < MiniTest::Unit::TestCase

  def test_gem_package
    gem = Gem::Specification.new do |g|
      g.name = "pkgr"
      g.version = "1.2.3"
      g.files = Rake::FileList["x"].resolve
    end
    pkg = Gem::PackageTask.new(gem)  do |p|
      p.package_files << "y"
    end
    assert_equal ["x", "y"], pkg.package_files
    assert_equal "pkgr-1.2.3.gem", pkg.gem_file
  end

  def test_gem_package_with_current_platform
    gem = Gem::Specification.new do |g|
      g.name = "pkgr"
      g.version = "1.2.3"
      g.files = Rake::FileList["x"].resolve
      g.platform = Gem::Platform::CURRENT
    end
    pkg = Gem::PackageTask.new(gem)  do |p|
      p.package_files << "y"
    end
    assert_equal ["x", "y"], pkg.package_files
    assert_match(/^pkgr-1\.2\.3-(\S+)\.gem$/, pkg.gem_file)
  end

  def test_gem_package_with_ruby_platform
    gem = Gem::Specification.new do |g|
      g.name = "pkgr"
      g.version = "1.2.3"
      g.files = Rake::FileList["x"].resolve
      g.platform = Gem::Platform::RUBY
    end
    pkg = Gem::PackageTask.new(gem)  do |p|
      p.package_files << "y"
    end
    assert_equal ["x", "y"], pkg.package_files
    assert_equal "pkgr-1.2.3.gem", pkg.gem_file
  end

end

