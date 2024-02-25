# Revolution UC 2024

In this project the goal is to make it seamless for hackathon participants to find groups and meetup with them within minutes. The functionality includes the press of a button which assigns someone an area to approach. This must be done by having pre input areas with a maximum capacity of 4 people. ( Or however many people the organizers choose to allow for a maximum group) When the user presses a button the system randomly will generate a number within the amount of available areas and tell the user to go to the area that has that random number assigned to it. 

**Arduino**
An Arduino Uno will be used in order to facilitate the button functionality aswell as to display the room to go to. The Arduino will also choose a random number based off the limits set by the amount of locations with open spots in Kintone's database.

**Kintone**
The Kintone IoT Microchip will be used to send the data of the button press to the database hosted on Kintone's servers. It will take in the number given by the arduino and index through the available database to return the location and number of people there.
