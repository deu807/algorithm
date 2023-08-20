#!/bin/bash

for week in $(ls -d [0-9]*주차); do
  # echo "# $week 결과" >$week/README.md
  # 각 문제 디렉토리를 순회
  echo "$(ls -d $week/*/)"
  # for problem in $(ls -d $week/*/); do
  # problem_name=$problem
  # echo "### $problem"

  # for user in 최은우 박상훈 김준기 정성헌 윤도운; do
  #   if [ -e $problem/$user.* ]; then
  #     echo "- $user: <font color=\"green\"> 성공 </font>" >> $week/README.md
  #   else
  #     echo "- $user: <font color=\"yellow\"> 보류 </font>" >> $week/README.md
  #   fi
  # done
  # done
done
