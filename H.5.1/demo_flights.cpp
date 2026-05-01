/*1. What does `AddVertex()` return?
        It returns a pointer which creates a new vertex. This makes it where we can store the memory 
        adress for futer edges.
2. What's the difference between `AddDirectedEdge()` and
`AddUndirectedEdge()`?
        Directed only does one direction, whereas undirected can go both directions.
3. What does `GetEdgesFrom()` give you? How is that different
from `GetEdgesTo()`?
        EdgesFrom returns a pointer to a vector containing all outgoing edges.
        EdgesTo returns a pointer to a vector of incoming edges
4. What does the edge `weight` represent in this demo?
        The weight in this demo is represented in the distance in miles between cities. 
*/



// demo_flights.cpp — CSC 249 Graph Demo
// Compile: g++ -std=c++17 demo_flights.cpp -o demo_flights
// Run: ./demo_flights
#include <iostream>
#include "Graph.h"
using namespace std;
int main() {
// Create a new Graph
Graph flights;
// Add cities as vertices
Vertex* tokyo = flights.AddVertex("Tokyo");
Vertex* nyc = flights.AddVertex("New York");
Vertex* london = flights.AddVertex("London");
Vertex* sydney = flights.AddVertex("Sydney");
Vertex* nc = flights.AddVertex("Fayetteville");
// Add flight routes as undirected edges (you can fly both ways)
flights.AddUndirectedEdge(tokyo, nyc, "6743 miles");
flights.AddUndirectedEdge(tokyo, london, "5941 miles");
flights.AddUndirectedEdge(tokyo, sydney, "4863 miles");
flights.AddUndirectedEdge(nyc, london, "3425 miles");
flights.AddUndirectedEdge(nyc, sydney, "9868 miles");
flights.AddUndirectedEdge(london, sydney, "10562 miles");
flights.AddUndirectedEdge(nc, nyc, "273 miles");
flights.AddUndirectedEdge(london,nc,"3928 miles");
flights.AddUndirectedEdge(nc,tokyo,"6967 miles");
flights.AddUndirectedEdge(nc, sydney, "9613 miles");
// Display each city and its flights
cout << "=== FLIGHT NETWORK ===" << endl << endl;
for (Vertex* city : flights.GetVertices()) {
cout << "Airport: " << city->label << endl;
cout << " Departures:" << endl;
for (Edge* flight : *flights.GetEdgesFrom(city)) {
cout << " -> " << flight->toVertex->label
<< " (" << flight->weight << ")" << endl;
}
cout << " Arrivals:" << endl;
for (Edge* flight : *flights.GetEdgesTo(city)) {
cout << " <- " << flight->fromVertex->label
<< " (" << flight->weight << ")" << endl;
}
cout << endl;
}
// Quick queries
cout << "=== QUERIES ===" << endl;
cout << "Direct flight Tokyo to London? "
<< (flights.HasEdge(tokyo, london) ? "Yes" : "No") << endl;
cout << "Total airports: " << flights.GetVertices().size() << endl;
cout << "Flights from New York: "
<< flights.GetEdgesFrom(nyc)->size() << endl;
return 0;
}
