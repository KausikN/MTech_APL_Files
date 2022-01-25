#include <iostream>
#include <climits>
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
        Graph(int numVertices){
            Init(numVertices);
        }
        
        /* Function to initialize the graph */
        void Init(int numVertices);
        
        /* Returns the number of vertices in the graph */
        int getVertices();
        
        /* Returns the number of edges in the graph */
        int getEdges();
        
        /* Returns the pointer to the first node with v as source */
        NodeType first(NodeType v);
        
        /* Returns the pointer to the node next to w whose source is v */
        NodeType next(NodeType v, NodeType w);
        
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

/******************************************************************************
   Init : Function to initialize the graph
   inputs : numVertices - Number of Vertices
   outputs : No Outputs
******************************************************************************/
void Graph::Init(int numVertices){
    numVertex = numVertices;
    numEdge = 0;

    // Init Adjacency List
    adj = new struct AdjList[numVertex];
    for(int i=0; i<numVertex; i++){
        adj[i].head = NULL;
    }
}

/******************************************************************************
   getVertices : Returns the number of vertices in the graph
   inputs : No Inputs
   outputs : Number of Vertices in Graph
******************************************************************************/
int Graph::getVertices(){
    return numVertex;
}

/******************************************************************************
   getEdges : Returns the number of edges in the graph
   inputs : No Inputs
   outputs : Number of Edges in Graph
******************************************************************************/
int Graph::getEdges(){
    return numEdge;
}

/******************************************************************************
   first : Returns the first node with v as source
   inputs : v - Source Vertex
   outputs : Pointer to the first node with v as source
******************************************************************************/
NodeType Graph::first(NodeType v){
    // If list is empty, return numVertex
    if (adj[v].head == NULL)
        return numVertex;
    // Return the first node
    return (adj[v].head)->node;
}

/******************************************************************************
   next : Returns the node next to w whose source is v
   inputs : v - Source Vertex
            w - Node whose next node we need
   outputs : Pointer to the node next to w whose source is v
******************************************************************************/
NodeType Graph::next(NodeType v, NodeType w){
    AdjNode *temp = adj[v].head;                /* Temp Pointer to the first node with v as source */

    // Loop to find the node with w as source and return the next node
    while(temp != NULL && temp->next != NULL){
        if(temp->node == w){
            return (temp->next)->node;
        }
        temp = temp->next;
    }
    // If the node is not found return numVertex
    return numVertex;
}

/******************************************************************************
   setEdge : Sets the weight as wt for the edge between v1 and v2
   inputs : v1 - Vertex 1
            v2 - Vertex 2
            wt - Weight of the edge
   outputs : No Outputs
******************************************************************************/
void Graph::setEdge(NodeType v1, NodeType v2, WeightType wt){
    // If v1 and v2 are same, dont add edge
    if(v1 == v2)
        return;

    AdjNode *temp = new AdjNode;                /* Pointer to the new AdjNode to be added to v1 */

    // Set node and weight
    temp->node = v2;
    temp->weight = wt;
    temp->next = adj[v1].head;

    // Add new node to head of adj list of v1
    adj[v1].head = temp;

    // Increment no of edges
    numEdge++;
}

/******************************************************************************
   delEdge : Removes the edge between v1 and v2
   inputs : v1 - Vertex 1
            v2 - Vertex 2
   outputs : No Outputs
******************************************************************************/
void Graph::delEdge(NodeType v1, NodeType v2){
    AdjNode *temp = adj[v1].head;               /* Temp Pointer to current AdjNode */
    AdjNode *prev = NULL;                       /* Temp Pointer to previous AdjNode */

    // Loop to find the v2 node in Adj List of v1
    while(temp != NULL){
        if(temp->node == v2){
            // If node is found at head of list, replace the head
            if(prev == NULL){
                adj[v1].head = temp->next;
            }
            // If node is found, replace next of prev node
            else{
                prev->next = temp->next;
            }
            numEdge--;
            return;
        }

        // Goto next node in list
        prev = temp;
        temp = temp->next;
    }
}

/******************************************************************************
   isEdge : Returns true if there exists an edge between v1 and v2
   inputs : v1 - Vertex 1
            v2 - Vertex 2
   outputs : Whether there exists an edge between v1 and v2
******************************************************************************/
bool Graph::isEdge(NodeType v1, NodeType v2){
    AdjNode *temp = adj[v1].head;               /* Temp Pointer to current AdjNode */

    // Loop to find the v2 node in Adj List of v1
    while(temp != NULL){
        // If v2 is found return true
        if(temp->node == v2){
            return true;
        }

        // Got next node in list
        temp = temp->next;
    }

    // return false if node is not found
    return false;
}

/******************************************************************************
   weight : Returns the weight of the edge connecting v1 and v2
   inputs : v1 - Vertex 1
            v2 - Vertex 2
   outputs : Weight of the edge connecting v1 and v2
******************************************************************************/
WeightType Graph::weight(NodeType v1, NodeType v2){
    AdjNode *temp = adj[v1].head;               /* Temp Pointer to current AdjNode */

    // Loop to find the v2 node in Adj List of v1
    while(temp != NULL){
        // If v2 is found return weight
        if(temp->node == v2){
            return temp->weight;
        }

        // Goto next node in list
        temp = temp->next;
    }

    // return numVertex if node is not found
    return INT_MAX;
}

/******************************************************************************
   getList : Returns the adjacency list header
   inputs : v - Vertex
   outputs : Pointer to the adjacency list header
******************************************************************************/
struct AdjNode* Graph::getList(NodeType v){
    return adj[v].head;
}


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
        struct HeapNode **heap;     // Heap array

    public:
        /*  Constructor */
        MinHeap (int cap){
            size = 0;
            capacity = cap;
            heap = new HeapNode*[capacity];
            position = new int[capacity];
            for(int i=0; i<capacity; i++){
                heap[i] = NULL;
                position[i] = -1;
            }
        }
        
        /* Member functions */

        struct HeapNode* createHeapNode(NodeType node, WeightType dist);
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

/******************************************************************************
   createHeapNode : Creates a new HeapNode
   inputs : node - Node to be added
            dist - Distance of the node from source
   outputs : Pointer to the new HeapNode
******************************************************************************/
struct MinHeap::HeapNode* MinHeap::createHeapNode(NodeType node, WeightType dist){
    struct HeapNode* newNode = new HeapNode;        /* Pointer to new heap node */
    newNode->node = node;
    newNode->dist = dist;
    return newNode;
}

/******************************************************************************
   swapHeapNode : Swaps two HeapNodes
   inputs : a - Heap Node 1
            b - Heap Node 2
   outputs : No Outputs
******************************************************************************/
void MinHeap::swapHeapNode(struct HeapNode** a, struct HeapNode** b){
    struct HeapNode* temp = *a;       
    *a = *b;
    *b = temp;
}

/******************************************************************************
   decreaseKey : Updates the value of node with new dist value
   inputs : node - node
            dist - new dist
   outputs : No Outputs
******************************************************************************/
void MinHeap::decreaseKey(NodeType node, WeightType dist){
    // If new distance is more than current distance, dont Update
    if (dist > (heap[position[node]])->dist){
        return;
    }

    int i = position[node];                         /* Position of node */
    heap[i]->dist = dist;                           /* Update the weight in heap array */

    // Loop if the node is not root (i == 0) and dist of i is less than parent ((i-1)/2 th position)
    int iParent = (i-1)/2;                          /* Position of parent of i */
    while(i > 0 && heap[i]->dist < heap[iParent]->dist){
        swapHeapNode(&heap[i], &heap[iParent]);
        position[heap[i]->node] = i;
        position[heap[iParent]->node] = iParent;
        i = iParent;
        iParent = (i-1)/2;
    }
}

/******************************************************************************
   insert : Inserts a new node in the heap
   inputs : node - node
            dist - dist of node
   outputs : No Outputs
******************************************************************************/
void MinHeap::insert(NodeType node, WeightType dist){
    // If heap is full, dont insert
    if(size == capacity){
        return;
    }

    // Create new heap node
    struct HeapNode* newNode = createHeapNode(node, dist);  /* Pointer of new node */
    heap[size] = newNode;
    position[node] = size;
    size++;

    // Update the heap
    decreaseKey(node, dist);
}

/******************************************************************************
   minHeapify : Heapifies the heap
   inputs : idx - node id
   outputs : No Outputs
******************************************************************************/
void MinHeap::minHeapify(NodeType idx){
    int i = idx;                                /* Current smallest index */
    int l = (2*i + 1);                          /* Left child index */
    int r = (2*i + 2);                          /* Right child index */

    // If left child position < i, set i as left child position
    if(l < size && heap[l]->dist < heap[i]->dist){
        i = l;
    }

    // If right child position < i, set i as right child position
    if(r < size && heap[r]->dist < heap[i]->dist){
        i = r;
    }

    // If i is not root, swap i and idx and recursively call minHeapify on i
    if(i != idx){
        swapHeapNode(&heap[i], &heap[idx]);
        position[heap[idx]->node] = idx;
        position[heap[i]->node] = i;
        minHeapify(i);
    }
}

/******************************************************************************
   deleteRoot : Deletes the root of the heap
   inputs :  No Inputs
   outputs : Pointer to the root of the heap
******************************************************************************/
struct MinHeap::HeapNode* MinHeap::deleteRoot(){
    // If heap is empty, return NULL
    if (isEmpty())
        return NULL;

    struct HeapNode* root = heap[0];            /* Pointer to root of heap */

    // Change the root to the last element in heap array
    heap[0] = heap[size-1];
    position[root->node] = size-1;
    position[heap[0]->node] = 0;
    size--;

    // Heapify the heap
    minHeapify(0);

    // Return the pointer to the deleted root
    return root;
}

/******************************************************************************
   printHeap : Prints the heap
   inputs :  No Inputs
   outputs : No Outputs
******************************************************************************/
void MinHeap::printHeap(){
    for(int i = 0; i < size; i++){
        cout << heap[position[i]]->node << " " << heap[position[i]]->dist << endl;
    }
}

/******************************************************************************
   isEmpty : Checks if the heap is empty
   inputs :  No Inputs
   outputs : true if heap is empty, false otherwise
******************************************************************************/
bool MinHeap::isEmpty(){
    return (size == 0);
}

/******************************************************************************
   inHeap : Checks if the node is in the heap
   inputs :  v - vertex to be checked
   outputs : true if node is in heap, false otherwise
******************************************************************************/
bool MinHeap::inHeap(int v){
    if (position[v] >= 0 && position[v] < size)
        return true;
    return false;
}



/******************************************************************************
   DijkstraAlgorithm : Dijkstra's Algorithm to compute shortest distance between 
                       source and all other vertices
   inputs : graph - Graph object
            source - Source vertex
   outputs : No Outputs
******************************************************************************/
void DijkstraAlgorithm(Graph graph, NodeType source){
    int     numVertices = graph.getVertices();      /* Number of vertices in the graph */

    // Initialise final min heap
    MinHeap finalMinHeap = MinHeap(numVertices);    /* Min Heap to store final distances */

    // Initialise MinHeap with source vertex
    MinHeap minHeap = MinHeap(numVertices);         /* Min Heap to store distances */
    minHeap.insert(source, 0);

    // Add all other vertices to the heap
    for(int i = 0; i < numVertices; i++){
        if(i != source){
            minHeap.insert(i, INT_MAX);
        }
    }

    // Loop until minHeap is empty
    while(!minHeap.isEmpty()){
        // Extract the minimum distance node from minHeap
        // In minHeap minimum distance node is simply the root
        struct MinHeap::HeapNode* minHeapNode = minHeap.deleteRoot();
        NodeType u = minHeapNode->node;

        // Add removed node to final min heap
        finalMinHeap.insert(minHeapNode->node, minHeapNode->dist);

        // If minHeap is at INT_MAX dist, no need to update any distances
        if (minHeapNode->dist == INT_MAX)
            continue;

        // Loop through all adjacent vertices of u
        AdjNode* vNode = graph.getList(u);
        NodeType v = vNode->node;
        while (vNode != NULL){
            v = vNode->node;
            // If v is in minHeap and w is not INT_MAX, Update the distance for v from source
            if(minHeap.inHeap(v)){
                WeightType w = graph.weight(u, v);
                if (w != INT_MAX){
                    WeightType dist = minHeapNode->dist + w;
                    // Update the distance of v from source if it is smaller than the current distance
                    minHeap.decreaseKey(v, dist);
                }
            }

            // Goto next adjacent vertex
            vNode = vNode->next;
        }
    }

    // Print the shortest distance from source to all other vertices
    finalMinHeap.printHeap();
}


/******************************************************************************
   main : Main function to run the program
   inputs : No Inputs
   outputs : 0 if no errors
******************************************************************************/
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int     numVertices;                        /* No of Vertices */
    int     numEdges;                           /* No of Edges */

    // Get Number of Vertices and Edges
    cin >> numVertices;
    cin >> numEdges;

    // Init Graph
    Graph   graph = Graph(numVertices);

    // Get Edges
    int     i;                                  /* Iterator Variable */
    for (i=0; i<numEdges; i++) {
        int u, v, weight;
        cin >> u;
        cin >> v;
        cin >> weight;

        // Add Edge to Groph
        graph.setEdge(u, v, weight);
        graph.setEdge(v, u, weight);
    }

    // Run Dijkstra Algorithm
    int     source = 0;                         /* Source Vertex as 0 */
    DijkstraAlgorithm(graph, source);

    return 0;
}