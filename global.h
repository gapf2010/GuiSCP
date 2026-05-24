#ifndef INCLUDE_GLOBAL_H
#define INCLUDE_GLOBAL_H

// Enum for conflict responses
typedef enum {
    CONFLICT_OVERWRITE = 1,
    CONFLICT_OVERWRITE_ALL = 2,
    CONFLICT_SKIP = 3,
    CONFLICT_SKIP_ALL = 4,
    CONFLICT_ABORT = 5
} ConflictResponse;

// Structure for application data
typedef struct {
    GtkWidget *local_tree;
    GtkWidget *remote_tree;
    GtkWidget *local_path_entry;
    GtkWidget *remote_path_entry;
    GtkWidget *host_entry;
    GtkWidget *user_entry;
    GtkWidget *password_entry;
    GtkWidget *port_entry;
    GtkWidget *key_file_entry;
    GtkWidget *protocol_combo;
    GtkWidget *connect_button;
    GtkWidget *status_label;
    GtkWidget *progress_bar;
    
    ssh_session session;
    sftp_session sftp;
    int connected;
    int protocol;  // 0 = SFTP, 1 = SCP
    
    GtkListStore *local_store;
    GtkListStore *remote_store;
    
    // Conflict resolution
    int overwrite_all;
    int skip_all;
    int copy_aborted;
} AppData;

#endif