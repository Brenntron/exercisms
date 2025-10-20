class LogLineParser
  def initialize(line)
    @line = line
  end

  def message
    return @line[/:(.*)/, 1].strip
  end

  def log_level
    @line[/([A-Z]+)/].downcase
  end

  def reformat
    return "#{message} (#{log_level})"
  end
end
