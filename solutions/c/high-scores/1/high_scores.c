#include "high_scores.h"

int32_t latest(const int32_t *scores, size_t scores_len) {
    if (scores_len == 0) {
        return 0;
    }
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
    if (scores_len == 0) {
        return 0;
    }
    int32_t best = scores[0];
    for (size_t i = 1; i < scores_len; i++) {
        if (scores[i] > best) {
            best = scores[i];
        }
    }
    return best;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
    if (scores_len == 0) {
        return 0;
    }

    // Create a copy of the scores to sort
    int32_t sorted_scores[scores_len];
    for (size_t i = 0; i < scores_len; i++) {
        sorted_scores[i] = scores[i];
    }

    // Quick sort the scores in descending order
    quickSort(sorted_scores, 0, scores_len - 1);

    size_t count = scores_len < 3 ? scores_len : 3;
    for (size_t i = 0; i < count; i++) {
        output[i] = sorted_scores[i];
    }

    return count;
}

// Partition function for quickSort using Hoare's partitioning scheme in descending order.
size_t partition(int32_t arr[], size_t low, size_t high) {
  int32_t pivot = arr[low];
  int i = low - 1;
  int j = high + 1;

  while (1) {
    do {
      i++;
    } while (arr[i] > pivot);

    do {
      j--;
    } while (arr[j] < pivot);

    if (i >= j) return j;

    // swap larger and smaller elements
    int32_t temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

void quickSort(int32_t arr[], size_t low, size_t high) {
  if (low < high) {
    size_t pi = partition(arr, low, high);
    quickSort(arr, low, pi);
    quickSort(arr, pi + 1, high);
  }
}
