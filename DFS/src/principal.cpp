#include <iostream>
#include "DFS.hpp"

using namespace std;

/**
 * Description: DFS algorithm
 * @author Vinicius Gabriel Angelozzi Verona de Resende
 * @date 10/10/2021
*/
int main() {

    /** 
     * Read input quantities: 
     * - number of vertices, number of edges; 
     * - graph direction binary & initial vertex
    */
    int q_vertices, q_edges, directed, initial_vertex;
    cin >> q_vertices >> q_edges >> directed >> initial_vertex;

    Graph* graph = new Graph(q_vertices);

    // Read all q_edges edges
    for (int i = 0; i < q_edges; i++){
        int v_source, v_destiny, e_value;
        bool e_exists = true;
        cin >> v_source >> v_destiny >> e_value;
        graph->insert(v_source, v_destiny, e_value, e_exists);

        // In case the the graph is an undirect graph, insert the returning edge
        if (directed == 0) {
            graph->insert(v_destiny, v_source, e_value, e_exists);
        }

    }

    // Generates transitivity_matrix[i][i] so that the DSF can visit the initial vertex even if the edge v0->v0 does not exixts
    for (int i = 0; i < q_vertices; i++){
        graph->insert(i + 1, i + 1, 0, false);
    }

    // Execute DFS algorithm which returns the vertex visiting order
    graph->DFS(initial_vertex);
    
    // Output vertices visiting order
    graph->printVisitingOrder();

    delete graph;
    return 0;
}