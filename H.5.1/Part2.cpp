//Domonic Yarnall

#include <iostream>
#include "Graph.h"
using namespace std;

int main() {

    Graph LuigiMansion;

    Vertex* foyer = LuigiMansion.AddVertex("Foyer");
    Vertex* hall = LuigiMansion.AddVertex("Hallway");
    Vertex* laundry = LuigiMansion.AddVertex("Laundery Room");
    Vertex* butler = LuigiMansion.AddVertex("Butler Room");
    Vertex* hidden = LuigiMansion.AddVertex("Hidden Room");
    Vertex* dining = LuigiMansion.AddVertex("Dining Room");
    Vertex* kitchen = LuigiMansion.AddVertex("Kitchen");
    Vertex boneyard = LuigiMansion.AddVertex("BoneYard");
    Vertex* grave = LuigiMansion.AddVertex("GraveYard");
    Vertex* ball = LuigiMansion.AddVertex("Ball Room");
    Vertex* storage = LuigiMansion.AddVertex("Storage Room");
    Vertex* teller = LuigiMansion.AddVertex("Fortune Teller");
    Vertex* mirror = LuigiMansion.AddVertex("Mirror Room");
    Vertex* rec = LuigiMansion.AddVertex("Rec Rooom");
    Vertex* court = LuigiMansion.AddVertex("CourtYard");
    Vertex* bath = LuigiMansion.AddVertex("Bathroom");
    Vertex* wash = LuigiMansion.AddVertex("Washroom");
    Vertex* pool = LuigiMansion.AddVertex("Billiards Room");
    Vertex* video = LuigiMansion.AddVertex("Projector Room");

    LuigiMansion.AddUndirectedEdge(hall, laundry, "1 Door");
    LuigiMansion.AddUndirectedEdge(hall, pool, "1 Door");
    LuigiMansion.AddUndirectedEdge(hall, dining, "1 Door");
    LuigiMansion.AddUndirectedEdge(hall, ball, "1 Door");
    LuigiMansion.AddUndirectedEdge(hall, teller, "1 Door");
    LuigiMansion.AddUndirectedEdge(hall, rec, "1 Door");
    LuigiMansion.AddUndirectedEdge(hall, bath, "1 Door");
    LuigiMansion.AddUndirectedEdge(hall, wash, "1 Door");
    LuigiMansion.AddUndirectedEdge(hall, court, "1 Door");
    LuigiMansion.AddUndirectedEdge(hall, butler, "2 Doors");
    LuigiMansion.AddUndirectedEdge(hall, kitchen, "2 Doors");
    LuigiMansion.AddUndirectedEdge(hall, storage, "2 Doors");
    LuigiMansion.AddUndirectedEdge(hall, mirror, "2 Doors");
    LuigiMansion.AddUndirectedEdge(hall, video, "2 Doors");
    LuigiMansion.AddUndirectedEdge(hall, hidden, "3 Doors");
    LuigiMansion.AddUndirectedEdge(hall, boneyard, "3 Doors");
    LuigiMansion.AddUndirectedEdge(hall, grave, "4 Doors");

    cout << "=== Luigi"s Mansion Floor 1 ===" << endl;
    for (Vertex* v : myGraph.GetVertices()) {
        cout << "Vertex: " << v->label << endl;
   }


return 0;
}