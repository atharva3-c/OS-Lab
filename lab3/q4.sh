#!/bin/bash

read -p "Basics: " basics
read -p "TA: " ta

gross_salary=$(echo "scale=2; $basics * 1.10 + $ta" | bc)

echo "Gross Salary: $gross_salary"

