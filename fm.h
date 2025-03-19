#include "bstset.h"
#include "provided.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
/*
airline names, flight numbers, departure times,durations
*/


//implemnt hte less than operator for the flightSegment struct

inline bool operator< (const FlightSegment& lhs, const FlightSegment& rhs)
{   
    return lhs.departure_time < rhs.departure_time;
}
class FlightManager : public FlightManagerBase{
    
    private:
        std::unordered_map<std::string, BSTSet<FlightSegment>> m_airports;
    public:
    FlightManager()
    {
        
    }
    ~FlightManager()
    {
        m_airports.clear();
    }
    std::vector<FlightSegment> find_flights(std::string source_airport, int start_time, int end_time)
    {
        if(m_airports.find(source_airport) == m_airports.end())
            return {};

        BSTSet<FlightSegment> outgoingFlights = m_airports[source_airport];
        FlightSegment tempFlight = FlightSegment("",0,"","",start_time,0);
       
        BSTSet<FlightSegment>::SetIterator itr = outgoingFlights.find_first_not_smaller(tempFlight);
         const FlightSegment* flight;
         std::vector<FlightSegment> flights;
         while((((flight = itr.get_and_advance()) != nullptr )&& (*flight).departure_time < end_time))
         {
            flights.push_back(*flight);
         }

         return flights;

    }

    /*
        1. Airline Name – The name of the airline offering the flight (e.g., Southwest).
        2. Flight# – The airline’s flight number (e.g., 3125).
        3. Source Airport – The three-letter airport code where the flight departs.
        4. Destination Airport – The three-letter airport code where the flight arrives.
        5. Departure Time (UTC) – A UNIX timestamp representing when the flight departs, as the
        number of seconds that have elapsed since Jan 1, 1970, 00:00:00 UTC.
        6. Arrival Time (UTC) – A UNIX timestamp representing when the flight arrives, in
        seconds.
        7. Duration (sec) – Flight duration in seconds. This will always be arrival time minus
        departure time.

        std::string airLine
        std::string flightNumber
        std::string sourceAirport
        std::string destinationAirport
        std::string departureTime
        std::string arrivalTime
        std::string duration


    */
   bool load_flight_data(std::string filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        // Could not open the file.
        return false;
    }

    std::string line;
    // Read file line by line.
    while (std::getline(infile, line)) {
        // Skip empty lines.
        if (line.empty())
            continue;
        
        // Split the line by commas.
        std::istringstream iss(line);
        std::vector<std::string> tokens;
        std::string token;
        while (std::getline(iss, token, ',')) {
            tokens.push_back(token);
        }
        
        // expect exactly 7 tokens per line.
        if (tokens.size() != 7) {
            continue;
        }
        
        std::string airline = tokens[0];
        int flightNo= std::stoi(tokens[1]);
        std::string source_airport = tokens[2];
        std::string destination_airport = tokens[3];
        // Field 4: Departure Time
        int departure_time  = std::stoi(tokens[4]);

        int flight_duration  = std::stoi(tokens[6]);

        FlightSegment flight = FlightSegment(airline,flightNo, source_airport, destination_airport, departure_time, flight_duration);
        if(m_airports.find(flight.source_airport) == m_airports.end())
            m_airports[flight.source_airport];
        m_airports[flight.source_airport].insert(flight);


    }
    
    infile.close();
    return true;
}

};
