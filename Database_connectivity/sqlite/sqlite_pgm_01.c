#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

static int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *errMsg = 0;
    int rc;

    // Open database
    rc = sqlite3_open("example.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s (code %d)\n", sqlite3_errmsg(db), rc);
        return 1;
    }
    else {
        printf("Database opened/created successfully.\n");
    }

    // Create Table (Create)
    const char *create_sql = "CREATE TABLE IF NOT EXISTS users ("
                             "id INTEGER PRIMARY KEY, "
                             "name TEXT NOT NULL, "
                             "email TEXT UNIQUE NOT NULL);";
    rc = sqlite3_exec(db, create_sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error (create): %s (code %d)\n", errMsg, rc);
        sqlite3_free(errMsg);
    } else {
        printf("Table created successfully.\n");
    }

    // Insert (Create)
    const char *insert_sql = "INSERT INTO users (name, email) VALUES ('Alice', 'alice@example.com'), ('Bob', 'bob@example.com');";
    rc = sqlite3_exec(db, insert_sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error (insert): %s (code %d)\n", errMsg, rc);
        sqlite3_free(errMsg);
    } else {
        printf("Data inserted successfully.\n");
    }

    // Read
    printf("Current users:\n");
    const char *select_sql = "SELECT * FROM users;";
    rc = sqlite3_exec(db, select_sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error (read): %s (code %d)\n", errMsg, rc);
        sqlite3_free(errMsg);
    }

    // Update
    const char *update_sql = "UPDATE users SET email = 'alice@newdomain.com' WHERE name = 'Alice';";
    rc = sqlite3_exec(db, update_sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error (update): %s (code %d)\n", errMsg, rc);
        sqlite3_free(errMsg);
    } else {
        printf("Update successful.\n");
    }

    // Read after update
    printf("After update:\n");
    rc = sqlite3_exec(db, select_sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error (select after update): %s (code %d)\n", errMsg, rc);
        sqlite3_free(errMsg);
    }

    // Delete
    const char *delete_sql = "DELETE FROM users WHERE name = 'Bob';";
    rc = sqlite3_exec(db, delete_sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error (delete): %s (code %d)\n", errMsg, rc);
        sqlite3_free(errMsg);
    } else {
        printf("Delete successful.\n");
    }

    // Read after delete
    printf("After delete:\n");
    rc = sqlite3_exec(db, select_sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error (select after delete): %s (code %d)\n", errMsg, rc);
        sqlite3_free(errMsg);
    }

    sqlite3_close(db);
    return 0;
}
