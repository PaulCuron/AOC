echo "Year to collect"
read year
echo "Day to collect"
read day

curl "https://adventofcode.com/$year/day/$day/input" -H "Cookie: session=53616c7465645f5f6696f524288bb4613251e645250ed172e2197f139f60b6934b25699916efc261c626ede61b8b9b6d7724fbb5e2d3fa1ad0b37b0e5349a806" > "input$day.txt"; 

