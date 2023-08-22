#!/bin/bash

OLD_IFS=$IFS
IFS=$'\n'


OUTPUT_FILE="RESULT.md"

# 파일 초기화
echo "|문제명| 최은우 | 김준기  | 박상훈  | 윤도운  | 정성헌 |" > $OUTPUT_FILE
echo "|------|:-------:|:-------:|:-------:|:-------:|:-------:|" >> $OUTPUT_FILE

# 각 주차 디렉터리를 순회
for week in $(ls -d [0-9]*주차); do
  # 각 문제 디렉터리를 순회
  for problem in $(ls -d $week/*/); do
    problemName=$(basename $problem)
    
    # 각 사용자의 풀이 확인
    user_results=""
    for user in "최은우" "김준기" "박상훈" "윤도운" "정성헌"; do
      user_file=$(ls $problem | grep $user)
      if [[ $user_file ]]; then
        user_results="${user_results}|<span style=\"color: #0f0\">o</span>"
      else
        user_results="${user_results}|<span style=\"color: #f00\">x</span>"
      fi
    done
    
    echo "|$problemName$user_results|" >> $OUTPUT_FILE
  done
done