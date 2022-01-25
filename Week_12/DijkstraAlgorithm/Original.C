#include <iostream>
using namespace std;

typedef int NodeType;
typedef int WeightType;

/*-------------------------------------------------------------------------
 *  AdjNode: Data type for one node of adj list
 -------------------------------------------------------------------------*/
 struct AdjNode {
     NodeType node;
     WeightType weight;
     struct AdjNode* next;
 };

/*-------------------------------------------------------------------------
 *  AdjList: Data type for adj list
 -------------------------------------------------------------------------*/
 struct AdjList{
     struct AdjNode *head;
 };

/*-------------------------------------------------------------------------
 *  Graph: Class for representing Graph
 -------------------------------------------------------------------------*/
 class Graph{

    int numVertex, numEdge;
    //int *mark;                                             // no of vertices in a graph
    struct AdjList *adj;
    public:
         /* Constructor to initialize the graph */
        Graph(int numVertex){
            Init(numVertex);
        }
     
         /* Function to initialize the graph */
        void Init(int numVertex);
     
         /* Returns the number of vertices in the graph */
        int getVertices();
     
         /* Returns the number of edges in the graph */
        int getEdges();
     
         /* Returns the pointer to the first node with v as source */
        int first(NodeType v);
     
         /* Returns the pointer to the node next to w whose source is v */
        int next(NodeType v, NodeType w);
     
         /* Sets the weight as wt for the edge between v1 and v2 */
        void setEdge(NodeType v1, NodeType v2, WeightType wt);
     
         /* removes the edge between v1 and v2 */
        void delEdge(NodeType v1, NodeType v2);
     
         /* Returns true if there exists an edge between v1 and v2 */
        bool isEdge(NodeType v1, NodeType v2);
     
         /* Returns the weight of the edge connecting v1 and v2 */
        WeightType weight(NodeType v1, NodeType v2);
     
         /* Returns the adjacency list header */
        struct AdjNode* getList(NodeType);
 };

#include <iostream>
#include <climits>
using namespace std;

typedef int NodeType;
typedef int WeightType;

class MinHeap{
    public:
        /* Structure to store node of the heap*/
        struct HeapNode{
            NodeType node;
            WeightType dist;
        };

    private:
        int size;                   // No of nodes in heap currently
        int capacity;               // Max number of nodes that can be in heap
        int* position;              // Position of vertex in the heap
        struct HeapNode **heap;                             

    public:
        /*  Constructor */
        MinHeap (int);
        
        /* Member functions */

        struct HeapNode* createHeapNode (NodeType node, WeightType dist);
        void swapHeapNode(struct HeapNode** a, struct HeapNode** b);
    
        /* Updates the value of node with new weight value*/
        void decreaseKey(NodeType, WeightType );
        void insert(NodeType node, WeightType dist);
        void minHeapify(NodeType idx);
        struct HeapNode* deleteRoot();
        void printHeap();
        bool isEmpty();
        bool inHeap(int v);
        
};

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  return 0;
}