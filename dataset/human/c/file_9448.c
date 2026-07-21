#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

#define QUEUE_SIZE 0x10000
typedef int Item;
Item queue[QUEUE_SIZE];
size_t queue_in = 0;
size_t queue_out = 0;
int queue_is_full = 0;

size_t inc_queue_index(size_t index)
{
  return (index + 1) % QUEUE_SIZE;
}

void queue_push(const Item* item)
{
  if(queue_is_full) {
    fputs("Queue is full.\n", stderr);
    exit(1);
  }
  memcpy(&queue[queue_in], item, sizeof(Item));
  queue_in = inc_queue_index(queue_in);
  queue_is_full = queue_in == queue_out;
}

void queue_pop(Item* result)
{
  if(queue_in == queue_out && !queue_is_full) {
    fputs("Queue is empty.\n", stderr);
    exit(1);
  }
  memcpy(result, &queue[queue_out], sizeof(Item));
  queue_out = inc_queue_index(queue_out);
  queue_is_full = 0;
}

void clear_queue()
{
  queue_in = 0;
  queue_out = 0;
  queue_is_full = 0;
}

int main()
{
  int num_people, days, rest_chocolate;
  scanf("%d%d%d", &num_people, &days, &rest_chocolate);

  long long total_chocolate = rest_chocolate;
  for(int i = 0; i < num_people; i++) {
    int a;
    scanf("%d", &a);
    total_chocolate += ((days-1) / a) + 1;
  }
  printf("%lld\n", total_chocolate);
  return 0;
}
