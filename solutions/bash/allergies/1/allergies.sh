#!/usr/bin/env bash

declare -A ALLERGENS=(
  [eggs]=1
  [peanuts]=2
  [shellfish]=4
  [strawberries]=8
  [tomatoes]=16
  [chocolate]=32
  [pollen]=64
  [cats]=128
)

main() {
  if [[ "$2" == "allergic_to" ]]; then
    local score=$1
    local allergen=$3
    local allergen_score=${ALLERGENS[$allergen]:-0}

    if (( score & allergen_score )); then
      echo "true"
    else
      echo "false"
    fi
  fi
  if [[ "$2" == "list" ]]; then
    local score=$1
    local result=()

    for allergen in "${!ALLERGENS[@]}"; do
      local allergen_score=${ALLERGENS[$allergen]}
      if (( score & allergen_score )); then
        result+=("$allergen_score:$allergen")
      fi
    done

    if (( ${#result[@]} )); then
      printf "%s\n" "${result[@]}" | sort -n | cut -d: -f2 | tr '\n' ' ' | sed 's/[[:space:]]*$//'
      echo
    fi
  fi
} 

main "$@"
