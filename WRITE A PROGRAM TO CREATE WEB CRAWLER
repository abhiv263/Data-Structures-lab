// WRITE A PROGRAM TO CREATE WEB CRAWLER.//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define URL_LENGTH 100

struct Queue {
    char urls[MAX][URL_LENGTH];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

int isFull(struct Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

void enqueue(struct Queue* q, const char* url) {
    if (isFull(q)) return;
    if (isEmpty(q)) q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    strcpy(q->urls[q->rear], url);
}

void dequeue(struct Queue* q, char* url) {
    if (isEmpty(q)) return;
    strcpy(url, q->urls[q->front]);
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

int alreadyVisited(char visited[][URL_LENGTH], int count, const char* url) {
    for (int i = 0; i < count; i++) {
        if (strcmp(visited[i], url) == 0)
            return 1;
    }
    return 0;
}

void simulateCrawler(const char* seedUrl) {
    struct Queue q;
    char visited[MAX][URL_LENGTH];
    int visitCount = 0;

    initQueue(&q);
    enqueue(&q, seedUrl);

    printf("Starting simulated web crawl from: %s\n\n", seedUrl);

    while (!isEmpty(&q) && visitCount < 10) {
        char currentUrl[URL_LENGTH];
        dequeue(&q, currentUrl);

        if (alreadyVisited(visited, visitCount, currentUrl)) continue;

        strcpy(visited[visitCount++], currentUrl);
        printf("Visited: %s\n", currentUrl);

        char fakeLinks[3][URL_LENGTH];
        for (int i = 0; i < 3; i++) {
            sprintf(fakeLinks[i], "%s/page%d", currentUrl, i + 1);
            if (!alreadyVisited(visited, visitCount, fakeLinks[i]))
                enqueue(&q, fakeLinks[i]);
        }
    }

    printf("\nCrawling completed. Total pages visited: %d\n", visitCount);
}

int main() {
    simulateCrawler("http://example.com");
    return 0;
}
