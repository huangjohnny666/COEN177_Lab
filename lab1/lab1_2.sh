# Name: Xiaoming Huang
# Date: Jan 9, 2024
# Title: Lab1 - step3
# Description: This program present some information such as HOME, USER, and PATH, then it ask for radius from the user and computes the area of a circle.

#!/bin/sh
echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$
user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."
if [ $user = "johnnyhuang" ]
then
    echo "Now you can proceed!"
else
    echo "Check who logged in!"
    exit 1 
fi

response="Yes"
while [ $response != "No" ]
do
    echo "Enter radius of circle: "
    read radius
    pi=3.14159
    area=`echo $radius \* $radius \* $pi | bc`
    echo "The area of the radius is $area"  
    echo "Would you like to repeat for another circle [Yes/No]?"
    read response
done