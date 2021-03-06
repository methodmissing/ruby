require 'test/unit'
require 'tmpdir'
require_relative 'envutil'

class TestDir_M17N < Test::Unit::TestCase
  def with_tmpdir
    Dir.mktmpdir {|dir|
      Dir.chdir(dir) {
        yield dir
      }
    }
  end

  ## UTF-8 default_external, no default_internal

  def test_filename_extutf8
    with_tmpdir {|d|
      assert_ruby_status(%w[-EUTF-8], <<-'EOS', nil, :chdir=>d)
        filename = "\u3042"
        File.open(filename, "w") {}
        ents = Dir.entries(".")
        exit ents.include?(filename)
      EOS
    }
  end

  def test_filename_extutf8_invalid
    with_tmpdir {|d|
      assert_ruby_status(%w[-EASCII-8BIT], <<-'EOS', nil, :chdir=>d)
        filename = "\xff".force_encoding("ASCII-8BIT") # invalid byte sequence as UTF-8
        File.open(filename, "w") {}
        ents = Dir.entries(".")
        exit ents.include?(filename)
      EOS
      assert_ruby_status(%w[-EUTF-8], <<-'EOS', nil, :chdir=>d)
        filename = "\xff".force_encoding("UTF-8") # invalid byte sequence as UTF-8
        File.open(filename, "w") {}
        ents = Dir.entries(".")
        exit ents.include?(filename)
      EOS
    }
  end

  def test_filename_as_bytes_extutf8
    with_tmpdir {|d|
      assert_ruby_status(%w[-EUTF-8], <<-'EOS', nil, :chdir=>d)
        filename = "\xc2\xa1".force_encoding("utf-8")
        File.open(filename, "w") {}
        ents = Dir.entries(".")
        exit ents.include?(filename)
      EOS
      assert_ruby_status(%w[-EUTF-8], <<-'EOS', nil, :chdir=>d)
        filename = "\xc2\xa1".force_encoding("euc-jp")
        begin
          open(filename) {}
          exit true
        rescue Errno::ENOENT
          exit false
        end
      EOS
      assert_ruby_status(%w[-EUTF-8], <<-'EOS', nil, :chdir=>d)
        filename1 = "\xc2\xa1".force_encoding("utf-8")
        filename2 = "\xc2\xa1".force_encoding("euc-jp")
        filename3 = filename1.encode("euc-jp")
        filename4 = filename2.encode("utf-8")
        s1 = File.stat(filename1) rescue nil
        s2 = File.stat(filename2) rescue nil
        s3 = File.stat(filename3) rescue nil
        s4 = File.stat(filename4) rescue nil
        exit (s1 && s2 && !s3 && !s4) ? true : false
      EOS
    }
  end

  ## UTF-8 default_external, EUC-JP default_internal

  def test_filename_extutf8_inteucjp_representable
    with_tmpdir {|d|
      assert_ruby_status(%w[-EUTF-8], <<-'EOS', nil, :chdir=>d)
        filename = "\u3042"
        File.open(filename, "w") {}
        ents = Dir.entries(".")
        exit ents.include?(filename)
      EOS
      assert_ruby_status(%w[-EUTF-8:EUC-JP], <<-'EOS', nil, :chdir=>d)
        filename = "\xA4\xA2".force_encoding("euc-jp")
        ents = Dir.entries(".")
        exit ents.include?(filename)
      EOS
      assert_ruby_status(%w[-EUTF-8:EUC-JP], <<-'EOS', nil, :chdir=>d)
        filename = "\xA4\xA2".force_encoding("euc-jp")
        begin
          open(filename) {}
          exit true
        rescue Errno::ENOENT
          exit false
        end
      EOS
    }
  end

  def test_filename_extutf8_inteucjp_unrepresentable
    with_tmpdir {|d|
      assert_ruby_status(%w[-EUTF-8], <<-'EOS', nil, :chdir=>d)
        filename1 = "\u2661" # WHITE HEART SUIT which is not representable in EUC-JP
        filename2 = "\u3042" # HIRAGANA LETTER A which is representable in EUC-JP
        File.open(filename1, "w") {}
        File.open(filename2, "w") {}
        ents = Dir.entries(".")
        exit ents.include?(filename1) && ents.include?(filename2)
      EOS
      assert_ruby_status(%w[-EUTF-8:EUC-JP], <<-'EOS', nil, :chdir=>d)
        filename1 = "\u2661" # WHITE HEART SUIT which is not representable in EUC-JP
        filename2 = "\xA4\xA2".force_encoding("euc-jp") # HIRAGANA LETTER A in EUC-JP
        ents = Dir.entries(".")
        exit ents.include?(filename1) && ents.include?(filename2)
      EOS
      assert_ruby_status(%w[-EUTF-8:EUC-JP], <<-'EOS', nil, :chdir=>d)
        filename1 = "\u2661" # WHITE HEART SUIT which is not representable in EUC-JP
        filename2 = "\u3042" # HIRAGANA LETTER A which is representable in EUC-JP
        filename3 = "\xA4\xA2".force_encoding("euc-jp") # HIRAGANA LETTER A in EUC-JP
        s1 = File.stat(filename1) rescue nil
        s2 = File.stat(filename2) rescue nil
        s3 = File.stat(filename3) rescue nil
        exit (s1 && s2 && s3) ? true : false
      EOS
    }
  end

  ## others

  def test_filename_bytes_euc_jp
    with_tmpdir {|d|
      assert_ruby_status(%w[-EEUC-JP], <<-'EOS', nil, :chdir=>d)
        filename = "\xA4\xA2".force_encoding("euc-jp")
        File.open(filename, "w") {}
        ents = Dir.entries(".")
        ents.each {|e| e.force_encoding("ASCII-8BIT") }
        exit ents.include?(filename.force_encoding("ASCII-8BIT"))
      EOS
    }
  end

  def test_filename_euc_jp
    with_tmpdir {|d|
      assert_ruby_status(%w[-EEUC-JP], <<-'EOS', nil, :chdir=>d)
        filename = "\xA4\xA2".force_encoding("euc-jp")
        File.open(filename, "w") {}
        ents = Dir.entries(".")
        exit ents.include?(filename)
      EOS
      assert_ruby_status(%w[-EASCII-8BIT], <<-'EOS', nil, :chdir=>d)
        filename = "\xA4\xA2"
        ents = Dir.entries(".")
        exit ents.include?(filename)
      EOS
    }
  end

  def test_filename_utf8_raw_name
    with_tmpdir {|d|
      assert_ruby_status(%w[-EUTF-8], <<-'EOS', nil, :chdir=>d)
        filename = "\u3042".force_encoding("utf-8")
        File.open(filename, "w") {}
        ents = Dir.entries(".")
        exit ents.include?(filename)
      EOS
      assert_ruby_status(%w[-EASCII-8BIT], <<-'EOS', nil, :chdir=>d)
        filename = "\u3042".force_encoding("ASCII-8BIT")
        ents = Dir.entries(".")
        exit ents.include?(filename)
      EOS
    }
  end

  def test_filename_ext_euc_jp_and_int_utf_8
    with_tmpdir {|d|
      assert_ruby_status(%w[-EEUC-JP], <<-'EOS', nil, :chdir=>d)
        filename = "\xA4\xA2".force_encoding("euc-jp")
        File.open(filename, "w") {}
        ents = Dir.entries(".")
        exit ents.include?(filename)
      EOS
      assert_ruby_status(%w[-EEUC-JP:UTF-8], <<-'EOS', nil, :chdir=>d)
        filename = "\u3042"
        ents = Dir.entries(".")
        exit ents.include?(filename)
      EOS
    }
  end

end

