//Write a program TO implement Depth First Search.//

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Graph {
    int vertices;
    int adjMatrix[MAX][MAX];
} Graph;

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, int vertex) {
    if (stack->top < MAX - 1) {
        stack->items[++stack->top] = vertex;
    }
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        return -1;
    }
    return stack->items[stack->top--];
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(Graph* graph, int start, int end) {
    graph->adjMatrix[start][end] = 1;
    graph->adjMatrix[end][start] = 1;
}

void dfs(Graph* graph, int startVertex) {
    Stack stack;
    initStack(&stack);
    int visited[MAX] = {0};

    push(&stack, startVertex);

    printf("DFS Traversal: ");

    while (!isEmpty(&stack)) {
        int currentVertex = pop(&stack);

        if (!visited[currentVertex]) {
            visited[currentVertex] = 1;
            printf("%d ", currentVertex);

            for (int i = graph->vertices - 1; i >= 0; i--) {
                if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                    push(&stack, i);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    Graph* graph = createGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 4, 5);

    dfs(graph, 0);

    free(graph);
    return 0;
}
