#!/bin/bash

OUTPUT_FILE="RESULT.md"

OLD_IFS=$IFS
IFS=$'\n'

echo "|문제명| 최은우 | 김준기  | 박상훈  | 윤도운  | 정성헌 |" > $OUTPUT_FILE
echo "|------|:-------:|:-------:|:-------:|:-------:|:-------:|" >> $OUTPUT_FILE

declare -A user_unsolved_count
user_unsolved_count["최은우"]=0
user_unsolved_count["김준기"]=0
user_unsolved_count["박상훈"]=0
user_unsolved_count["윤도운"]=0
user_unsolved_count["정성헌"]=0

for week in $(ls -d [0-9]*주차); do
  for problem in $(ls -d $week/*/); do
    problemName=$(basename $problem)
    
    user_results=""
    for user in "최은우" "김준기" "박상훈" "윤도운" "정성헌"; do
      user_file=$(ls $problem | grep $user)
      if [[ $user_file ]]; then
        user_results="${user_results}|<span style=\"color: #0f0\">o</span>"
      else
        user_results="${user_results}|<span style=\"color: #f00\">x</span>"
        user_unsolved_count[$user]=$((user_unsolved_count[$user]+1))
      fi
    done
    
    echo "|$problemName$user_results|" >> $OUTPUT_FILE
  done
done

echo "" >> $OUTPUT_FILE
echo "### 안 푼 문제의 개수" >> $OUTPUT_FILE
for user in "최은우" "김준기" "박상훈" "윤도운" "정성헌"; do
    echo "- $user: ${user_unsolved_count[$user]}개" >> $OUTPUT_FILE
done
