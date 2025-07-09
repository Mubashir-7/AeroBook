# AeroBook
Airline Reservation System
This repository contains the source code for a simple Airline Reservation System developed in C. The system is designed to manage flight and passenger information, allowing for the addition, editing, and deletion of flight records, as well as enabling passengers to reserve seats and view flight schedules. The program utilizes file handling (Flights.txt) to ensure data persistence across sessions.

Table of Contents
Features

Program Structure and Pipelines

Data Structures

File Handling

Core Functions and Their Interactions

How to Compile and Run

Future Enhancements

Contributing

License

Features
The program offers the following functionalities:

Reserve Seat: Allows users to reserve seats on available flights.

Flights Schedule: Displays details of a specific flight based on its flight number.

Flight Details (Admin): Provides authorized personnel access to manage flight records after a PIN code verification.

Add Flight: Adds new flight information to the system.

Edit Flight: Modifies existing flight records.

Delete Flight: Removes flight records from the system.

Flight Leave and Arrive: Allows for updating departure and arrival times of flights.

Back To Menu: Navigates back to the main or previous menu.

(Note: "User Ticket" and "Display Passenger" features are mentioned in the documentation but are largely conceptual or incomplete in the provided code.)

Program Structure and Pipelines
The program is structured using several C functions and two primary structures: Flights and Passenger.

Data Structures
struct Flights: Represents a single flight record.

FlightNo (char array): Unique identifier for the flight.

FlightName (char array): Name of the airline or flight.

From (char array): Departure location.

Destination (char array): Arrival destination.

Departure (char array): Scheduled departure time.

Arrival (char array): Scheduled arrival time.

Price (char array/int): Seat price.

(Planned enhancement: Total Seats to manage seat availability.)

struct Passenger: Represents a passenger's reservation (details vary slightly across provided files).

FlightNo (char array): The flight number for the reserved seat (in tempProject.c).

ID (int)/PassengerID (int/char array): Unique identifier for the passenger.

Name (char array): Passenger's name.

Seats (int): Number of seats reserved by the passenger.

File Handling
Flights.txt: This text file serves as the database for flight records. Each line stores flight data in a comma-separated format.

filereadFlights(): Reads flight data from Flights.txt into an in-memory array of Flights structs. It parses each line, tokenizing by commas.

filewriteFlights(): Writes the current in-memory flight data back to Flights.txt, ensuring that any additions, edits, or deletions are saved.

Core Functions and Their Interactions
The program flow is primarily managed by a main function that presents a menu, and various other functions handle specific tasks:

main():

Serves as the program's entry point.

Displays the main menu with options like "Reserve Seat," "Flights Schedule," "Passenger Records," and "Flight Details."

Uses a switch statement to direct control to the chosen function.

system("cls") (or clrscr() on some compilers) is used to clear the console screen for better UI.

FlightDetails():

An administrative section requiring a PIN (e.g., 9078) for access.

Presents a sub-menu for managing flight records: "Add New Flight," "Edit Flight Record," "Delete Flight," "Flight Arrival and Departure," and "Back to Main Menu."

Another switch statement navigates to the specific flight management functions.

AddFlight():

Prompts the user to input details for a new flight.

Includes basic input validation (e.g., using goto statements in tempProject.c).

Adds the new flight to the in-memory array and calls filewriteFlights() to save it.

FlightsTable() (in tempProject.c):

Displays all currently loaded flights in a formatted table.

FlightNoSearch(char num[10]):

Searches the in-memory flight array for a given flight number.

Returns the array index if found, or -1 otherwise.

In ARS.c, filereadFlights() is called within this function to ensure data freshness.

EditFlight():

Allows modification of an existing flight record by flight number.

Displays current details, prompts for new ones, updates the array, and saves changes via filewriteFlights().

ArrivalDeparture():

Enables updating the departure and arrival times for a specified flight.

Changes are intended to be saved to Flights.txt.

DeleteFlight():

Removes a flight record based on its flight number.

Shifts subsequent records to maintain array integrity.

Intended to call filewriteFlights() to persist the deletion.

ReserveSeats() (in tempProject.c):

Prompts for departure and destination to find available flights.

Allows the user to select a flight and specify the number of seats.

(Future: Display ticket information; check against Total Seats.)

SearchFlight(char dep[20], char des[20]) (in tempProject.c):

Assists ReserveSeats() by finding and displaying flights that match the provided departure and destination.

FlightSchedule():

Takes a flight number as input and displays its detailed schedule.

DisplayPassengers() / PassengerRecords() (conceptual):

Intended to display passenger-specific reservation details, likely involving a separate "Passengers.txt" file.

Pipeline Summary
Start: The main() function initializes the program.

Load Data: filereadFlights() is typically called early to load existing flight data into memory.

User Interaction Loop: The program continually presents the main menu until the user chooses to quit.

Feature Execution: Based on user input, the relevant function (e.g., ReserveSeats(), FlightDetails(), FlightSchedule()) is executed.

Data Modification: Functions like AddFlight(), EditFlight(), DeleteFlight(), and ArrivalDeparture() modify the in-memory flight data.

Data Persistence: After data modifications, filewriteFlights() is invoked to save the updated state to Flights.txt.

Exit: The program terminates when the user selects the "Quit" option from the main menu.

How to Compile and Run
To compile and run this C program, you will need a C compiler (e.g., GCC).

Save the files: Save the .c files (e.g., ARS.c, ARSYSTEM.c, tempProject.c) to your local machine. Note that these files represent different stages or variations of the project; you should choose one as your primary source file (e.g., ARS.c or tempProject.c). The documentation (AR System.docx) provides context for the overall system.

Compile: Open a terminal or command prompt, navigate to the directory where you saved the files, and compile using a C compiler. For example, using GCC:



gcc ARS.c -o ars
(Replace ARS.c with the name of the .c file you choose as your main program, e.g., tempProject.c)

Run: After successful compilation, run the executable:



./ars
The program will then display the main menu in the console.

Future Enhancements
Based on the documentation and incomplete code sections, potential future enhancements include:

Complete "User Ticket" and "Display Passenger" features: Implement full functionality for managing and displaying passenger-specific ticket and flight details, possibly with a dedicated Passengers.txt file.

Seat Availability Management: Implement the Total Seats feature in the Flights structure to prevent over-booking during seat reservations.

Robust Input Validation: Enhance input validation to handle various invalid inputs more gracefully, reducing reliance on goto statements.

Improved User Interface: While a console application, consider using libraries for more advanced console UI elements if desired.

Error Handling: Implement more comprehensive error handling for file operations and other critical sections.

Nested Structures for Passenger-Flight Linkage: Explore implementing a "nested structure technique to connect flight details to passenger details" as suggested in the documentation for a more robust relationship between these entities.

Contributing
Feel free to fork this repository, open issues, or submit pull requests if you have suggestions for improvements or bug fixes.

License
This project is open-source and available under the MIT License.
