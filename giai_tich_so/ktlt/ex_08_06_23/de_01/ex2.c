#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char sach[100];
    char tacgia[100];
    int nam;
} Book;

void find_book(Book *books, int n, const char *book_name) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(books[i].sach, book_name) == 0) {
            printf("Quyen sach '%s' co tac gia '%s' va nam xuat ban '%d'\n", books[i].sach, books[i].tacgia, books[i].nam);
            return;
        }
    }
    printf("Khong tim thay quyen sach '%s'\n", book_name);
}

void sort_books(Book *books, int n) {
    int i, j;
    Book temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (books[i].nam > books[j].nam) {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}

void save_books(Book *books, int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo file %s de ghi\n", filename);
        return;
    }
    int i;
    for (i = 0; i < n; i++) {
        if (books[i].nam < 2000) {
            fprintf(file, "Sach: %s\n", books[i].sach);
            fprintf(file, "Tac gia: %s\n", books[i].tacgia);
            fprintf(file, "Nam xuat ban: %d\n\n", books[i].nam);
        }
    }
    fclose(file);
}

int main() {
    FILE *file = fopen("sach.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file sach.txt\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);
    Book *books = (Book*)malloc(n * sizeof(Book));

    int i;
    char buffer[100];
    fgets(buffer, sizeof(buffer), file); // Đọc dòng thừa sau khi đọc số lượng sách

    for (i = 0; i < n; i++) {
        fgets(books[i].sach, sizeof(books[i].sach), file);
        books[i].sach[strcspn(books[i].sach, "\n")] = '\0'; // Xóa kí tự newline (\n) cuối chuỗi

        fgets(books[i].tacgia, sizeof(books[i].tacgia), file);
        books[i].tacgia[strcspn(books[i].tacgia, "\n")] = '\0'; // Xóa kí tự newline (\n) cuối chuỗi

        fscanf(file, "%d", &books[i].nam);
        fgets(buffer, sizeof(buffer), file); // Đọc dòng thừa sau mỗi quyển sách
    }
    fclose(file);

    char book_name[100];
    printf("Nhap ten sach can tim: ");
    scanf("%s", book_name);

    find_book(books, n, book_name);
    sort_books(books, n);
    save_books(books, n, "sach_out.txt");

    free(books);
    return 0;
}
