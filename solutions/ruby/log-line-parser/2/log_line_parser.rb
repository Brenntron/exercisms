class LogLineParser
  def initialize(line)
    @line = line
  end

  def message
    @line[/:(.*)/, 1].strip
  end

  def log_level
    @line[/([A-Z]+)/].downcase
  end

  def reformat
    "#{message} (#{log_level})"
  end
end
