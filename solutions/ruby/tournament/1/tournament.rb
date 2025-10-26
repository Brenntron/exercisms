class Tournament
  def self.tally(input)
    team_name_length = 30
    games = input.split("\n")
    score_map = {}
    scoreboard = <<~SCOREBOARD
    Team                           | MP |  W |  D |  L |  P
    SCOREBOARD

    for game in games do
      team_1, team_2, result = game.split(';')
      [team_1, team_2].each { |team| score_map[team] ||= { mp: 0, w: 0, d: 0, l: 0, p: 0 } }

      score_map[team_1][:mp] += 1
      score_map[team_2][:mp] += 1

      if result == 'win'
        score_map[team_1][:p] += 3
        score_map[team_1][:w] += 1
        score_map[team_2][:l] += 1
      elsif result == 'draw'
        score_map[team_1][:p] += 1
        score_map[team_2][:p] += 1
        score_map[team_1][:d] += 1
        score_map[team_2][:d] += 1
      else
        score_map[team_2][:p] += 3
        score_map[team_2][:w] += 1
        score_map[team_1][:l] += 1
      end
    end

    score_map = score_map.sort_by { |team, scores| [-scores[:p], team] }

    scoreboard_rows = score_map.map do |team, scores|
      format("%-#{team_name_length}s | %2d | %2d | %2d | %2d | %2d\n",
            team, scores[:mp], scores[:w], scores[:d], scores[:l], scores[:p])
    end

    scoreboard += scoreboard_rows.join()
  end
end
