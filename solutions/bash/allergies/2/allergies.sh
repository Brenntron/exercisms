#!/usr/bin/env bash

(( $# == 3 || $# == 2 )) || exit 1

ALLERGENS=(
  eggs
  peanuts
  shellfish
  strawberries
  tomatoes
  chocolate
  pollen
  cats
)

boolRC() { (( $? == 0 )) && echo true || echo false; }

allergic_to() {
  score=$1
  allergen=$2
  v=1
  for known_allergen in "${ALLERGENS[@]}"; do
    if [[ $known_allergen = "$allergen" ]]; then
      (( score & v ))
      boolRC
    fi
    (( v <<= 1 ))
  done
}

list() {
  score=$1
  v=1
  allergies=()
  for allergen in "${ALLERGENS[@]}"; do
    (( score & v )) && allergies+=( "$allergen" )
    (( v <<= 1 ))
  done
  echo "${allergies[@]}"
} 

"$2" "$1" "$3"
