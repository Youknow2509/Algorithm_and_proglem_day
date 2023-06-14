#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_UNIVERSITIES 4

typedef struct {
    char name[MAX_LENGTH];
    float score;
    char university[MAX_LENGTH];
} Contestant;

void readContestantsFromFile(const char* filename, Contestant* contestants, int* numContestants) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo tap tin!\n");
        exit(1);
    }

    fscanf(file, "%d", numContestants);
    fgetc(file); // Đọc ký tự newline sau số thí sinh

    for (int i = 0; i < *numContestants; i++) {
        fgets(contestants[i].name, MAX_LENGTH, file);
        contestants[i].name[strcspn(contestants[i].name, "\n")] = '\0'; // Loại bỏ ký tự newline

        fscanf(file, "%f", &contestants[i].score);
        fgetc(file); // Đọc ký tự newline sau số điểm

        fgets(contestants[i].university, MAX_LENGTH, file);
        contestants[i].university[strcspn(contestants[i].university, "\n")] = '\0'; // Loại bỏ ký tự newline
    }

    fclose(file);
}

void calculateTotalScore(const Contestant* contestants, int numContestants, float* totalScores, const char** universities) {
    for (int i = 0; i < numContestants; i++) {
        for (int j = 0; j < MAX_UNIVERSITIES; j++) {
            if (strcmp(contestants[i].university, universities[j]) == 0) {
                totalScores[j] += contestants[i].score;
                break;
            }
        }
    }
}

int findMaxScoreUniversity(const float* totalScores) {
    float maxScore = totalScores[0];
    int maxIndex = 0;

    for (int i = 1; i < MAX_UNIVERSITIES; i++) {
        if (totalScores[i] > maxScore) {
            maxScore = totalScores[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

void findContestantByName(const Contestant* contestants, int numContestants, const char* name, Contestant* foundContestant) {
    for (int i = 0; i < numContestants; i++) {
        if (strcmp(contestants[i].name, name) == 0) {
            strcpy(foundContestant->name, contestants[i].name);
            foundContestant->score = contestants[i].score;
            strcpy(foundContestant->university, contestants[i].university);
            return;
        }
    }

    strcpy(foundContestant->name, "");
    foundContestant->score = 0.0;
    strcpy(foundContestant->university, "");
}

void writeContestantToFile(const char* filename, const Contestant* contestant) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo tap tin!\n");
        exit(1);
    }

    fprintf(file, "Thong tin thi sinh:\n");
    fprintf(file, "Ho ten: %s\n", contestant->name);
    fprintf(file, "Diem: %.2f\n", contestant->score);
    fprintf(file, "Truong: %s\n", contestant->university);

    fclose(file);
}

int main() {
    Contestant contestants[MAX_LENGTH];
    int numContestants;
    float totalScores[MAX_UNIVERSITIES] = {0.0};
    const char* universities[MAX_UNIVERSITIES] = {"A", "B", "C", "D"};
    char searchName[MAX_LENGTH];
    Contestant foundContestant;

    readContestantsFromFile("inp.txt", contestants, &numContestants);
    calculateTotalScore(contestants, numContestants, totalScores, universities);

    int maxScoreUniversityIndex = findMaxScoreUniversity(totalScores);
    printf("Tong diem cua tung truong:\n");
    for (int i = 0; i < MAX_UNIVERSITIES; i++) {
        printf("Truong %s: %.2f\n", universities[i], totalScores[i]);
    }
    printf("Truong co tong diem cao nhat: %s\n", universities[maxScoreUniversityIndex]);

    printf("Nhap ten thi sinh can tim: ");
    fgets(searchName, MAX_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    findContestantByName(contestants, numContestants, searchName, &foundContestant);

    writeContestantToFile("output.txt", &foundContestant);
    printf("Da ghi ket qua vao file output.txt\n");

    return 0;
}
