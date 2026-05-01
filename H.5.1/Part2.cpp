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
    Vertex* boneyard = LuigiMansion.AddVertex("BoneYard");
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
    LuigiMansion.AddUndirectedEdge(laundry, butler, "1 Door");
    LuigiMansion.AddUndirectedEdge(hidden, butler, "1 Door");
    LuigiMansion.AddUndirectedEdge(dining, kitchen, "1 Door");
    LuigiMansion.AddUndirectedEdge(kitchen, boneyard, "1 Door");
    LuigiMansion.AddUndirectedEdge(boneyard, grave, "1 Door");
    LuigiMansion.AddUndirectedEdge(ball, storage, "1 Door");
    LuigiMansion.AddUndirectedEdge(teller, mirror, "1 Door");
    LuigiMansion.AddUndirectedEdge(rec, court, "1 Door");
    LuigiMansion.AddUndirectedEdge(pool, video, "1 Door");
    LuigiMansion.AddUndirectedEdge(foyer,hall, "1 Door");



    cout << "=== Luigi's Mansion Floor 1 ===" << endl;
    for (Vertex* v : LuigiMansion.GetVertices()) {
        cout << "Room: " << v->label << endl;
        
        for (Edge* e : *LuigiMansion.GetEdgesFrom(v)) {
            cout << "  -> leads to: " << e->toVertex->label 
                 << " (" << e->weight << ")" << endl;
        }
        cout << endl;
    }

    
    cout << "==Queries=="<<endl;
       //queriy 1
    for (Vertex* v : LuigiMansion.GetVertices()) {
        cout << v->label << " has " 
             << LuigiMansion.GetEdgesFrom(v)->size() 
             << " connections" << endl;
    }
    cout << endl;
       //queriy 2
    cout << "Direct connection between Hallway and Kitchen? " 
         << (LuigiMansion.HasEdge(hall, kitchen) ? "Yes" : "No") << endl;
    cout << endl;

   //queriy 3
    Vertex* found = LuigiMansion.GetVertex("Hidden Room");
    if (found) {
        cout << "Found: " << found->label << endl;
    } else {
        cout << "Not found!" << endl;
    }
    cout << endl;

      //queriy 4
    cout << "Total Vertices (Rooms): " << LuigiMansion.GetVertices().size() << endl;
    cout << "Total Edges (Paths): " << LuigiMansion.GetEdges().size() << endl;

return 0;
}