#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "random_generator.h"
#include "sorting_algorithms.h"
//You can use the array But i can't able to get using array so i am using the struct

typedef struct {
    GtkWidget *dataset_size_entry;
    GtkWidget *min_value_entry;
    GtkWidget *max_value_entry;
} UserData;

typedef struct{
    GtkWidget *quick_sort_checkbox, *radix_sort_checkbox, *insertion_sort_checkbox;
    GtkWidget *bubble_sort_checkbox, *merge_sort_checkbox, *heap_sort_checkbox, *shell_sort_checkbox;
     GtkWidget *dataset_size_entry;
    GtkWidget *min_value_entry;
    GtkWidget *max_value_entry;
}results;
typedef struct {
    int id;
    double val1, val2, val3, val4, val5, val6, val7,val8,val9;
} Row;

// For comparing the size of the two results
int compareRows(const void *a, const void *b) {
    Row *rowA = (Row *)a;
    Row *rowB = (Row *)b;
    return rowA->id - rowB->id;
}

// Function declaration
void generate_dataset_callback(GtkWidget *widget, gpointer data);
void sort_callback(GtkWidget *widget, gpointer data);
void plot_callback(GtkWidget *widget, gpointer data);
double sorting_times[10]={0.0};
GtkWidget *create_ui() {
    GtkWidget *window, *vbox, *hbox, *button, *label;
    GtkWidget *dataset_size_label, *min_value_label, *max_value_label;
    GtkWidget *dataset_size_entry, *min_value_entry, *max_value_entry;
     GtkWidget *quick_sort_checkbox, *radix_sort_checkbox, *insertion_sort_checkbox;
    GtkWidget *bubble_sort_checkbox, *merge_sort_checkbox, *heap_sort_checkbox, *shell_sort_checkbox;
    GtkWidget *plot_button,*sort_button;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Sorting Algorithms");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);
  
  
    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

    label = gtk_label_new("Generate Random Dataset:");
    gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);

    dataset_size_label = gtk_label_new("Size:");
    gtk_box_pack_start(GTK_BOX(hbox), dataset_size_label, FALSE, FALSE, 0);

    dataset_size_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), dataset_size_entry, FALSE, FALSE, 0);

    min_value_label = gtk_label_new("Min Value:");
    gtk_box_pack_start(GTK_BOX(hbox), min_value_label, FALSE, FALSE, 0);

    min_value_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), min_value_entry, FALSE, FALSE, 0);

    max_value_label = gtk_label_new("Max Value:");
    gtk_box_pack_start(GTK_BOX(hbox), max_value_label, FALSE, FALSE, 0);

    max_value_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), max_value_entry, FALSE, FALSE, 0);

    button = gtk_button_new_with_label("Generate Dataset");
    gtk_box_pack_start(GTK_BOX(hbox), button, FALSE, FALSE, 0);

   
    UserData *user_data = malloc(sizeof(UserData));
    user_data->dataset_size_entry = dataset_size_entry;
    user_data->min_value_entry = min_value_entry;
    user_data->max_value_entry = max_value_entry;

  
    g_signal_connect(button, "clicked", G_CALLBACK(generate_dataset_callback), user_data);
    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

    label = gtk_label_new("Select Sorting Algorithm:");
    gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);

    quick_sort_checkbox = gtk_check_button_new_with_label("Quick Sort");
    gtk_box_pack_start(GTK_BOX(hbox), quick_sort_checkbox, FALSE, FALSE, 0);

    radix_sort_checkbox = gtk_check_button_new_with_label("Radix Sort");
    gtk_box_pack_start(GTK_BOX(hbox), radix_sort_checkbox, FALSE, FALSE, 0);

    insertion_sort_checkbox = gtk_check_button_new_with_label("Insertion Sort");
    gtk_box_pack_start(GTK_BOX(hbox), insertion_sort_checkbox, FALSE, FALSE, 0);

    bubble_sort_checkbox = gtk_check_button_new_with_label("Bubble Sort");
    gtk_box_pack_start(GTK_BOX(hbox), bubble_sort_checkbox, FALSE, FALSE, 0);

    merge_sort_checkbox = gtk_check_button_new_with_label("Merge Sort");
    gtk_box_pack_start(GTK_BOX(hbox), merge_sort_checkbox, FALSE, FALSE, 0);

    heap_sort_checkbox = gtk_check_button_new_with_label("Heap Sort");
    gtk_box_pack_start(GTK_BOX(hbox), heap_sort_checkbox, FALSE, FALSE, 0);

    shell_sort_checkbox = gtk_check_button_new_with_label("Shell Sort");
    gtk_box_pack_start(GTK_BOX(hbox), shell_sort_checkbox, FALSE, FALSE, 0);

    sort_button = gtk_button_new_with_label("Sort");
    gtk_box_pack_start(GTK_BOX(hbox), sort_button, FALSE, FALSE, 0);

    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

     plot_button = gtk_button_new_with_label("Compare All Results");
    gtk_box_pack_start(GTK_BOX(vbox), plot_button, FALSE, FALSE, 0);

     results *user_d = malloc(sizeof(results));
    user_d->dataset_size_entry = dataset_size_entry;
    user_d->min_value_entry = min_value_entry;
     user_d->max_value_entry = max_value_entry;
    user_d->quick_sort_checkbox = quick_sort_checkbox;
    user_d->radix_sort_checkbox = radix_sort_checkbox;
    user_d->insertion_sort_checkbox = insertion_sort_checkbox;
    user_d->bubble_sort_checkbox = bubble_sort_checkbox;
    user_d->merge_sort_checkbox = merge_sort_checkbox;
    user_d->heap_sort_checkbox = heap_sort_checkbox;
    user_d->shell_sort_checkbox = shell_sort_checkbox;
 

    g_signal_connect(sort_button, "clicked", G_CALLBACK(sort_callback), user_d);
     g_signal_connect(plot_button, "clicked", G_CALLBACK(plot_callback), NULL);
    gtk_widget_show_all(window);

    return window;
}

void generate_dataset_callback(GtkWidget *widget, gpointer data) {
    UserData *user_data = (UserData *)data;

    int size, min, max;

   
    if (sscanf(gtk_entry_get_text(GTK_ENTRY(user_data->dataset_size_entry)), "%d", &size) != 1 ||
        sscanf(gtk_entry_get_text(GTK_ENTRY(user_data->min_value_entry)), "%d", &min) != 1 ||
        sscanf(gtk_entry_get_text(GTK_ENTRY(user_data->max_value_entry)), "%d", &max) != 1) {
        g_print("Error: Invalid input.\n");
        return;
    }

  
    if (size <= 0) {
        g_print("Error: Dataset size must be a positive integer.\n");
        return;
    }

    if (min > max) {
        g_print("Error: Min value must be less than or equal to max value.\n");
        return;
    }

   
    generate_dataset(size, min, max, "dataset.txt");
}
void sort_callback(GtkWidget *widget, gpointer data) {
   results *user_d=(results *)data;
  
    GtkWidget *dataset_size_entry = gtk_widget_get_parent(widget);
    GtkWidget *min_value_entry = gtk_widget_get_parent(dataset_size_entry);
    GtkWidget *max_value_entry = gtk_widget_get_parent(min_value_entry);

    int size, min, max;
    sscanf(gtk_entry_get_text(GTK_ENTRY(user_d->dataset_size_entry)), "%d", &size);
    sscanf(gtk_entry_get_text(GTK_ENTRY(user_d->min_value_entry)), "%d", &min);
    sscanf(gtk_entry_get_text(GTK_ENTRY(user_d->max_value_entry)), "%d", &max);

    int *arr = (int *)malloc(size * sizeof(int));
  
    read_dataset("dataset.txt", arr, size);

   int sort_count = 0;
FILE *csv_file = fopen("sorting_times.csv", "r+");
if (!csv_file) {
    perror("Error opening CSV file");
    return;
}

char buffer[1024];
fgets(buffer, 1024, csv_file); 
int num_lines = 0;
while (fgets(buffer, 1024, csv_file)) {
    num_lines++;
    sort_count++; 
}
//csv only save upto 5 results if exceeds clears all
if (sort_count >= 5) {
    fseek(csv_file, 0, SEEK_SET); 
    fgets(buffer, 1024, csv_file);
    fseek(csv_file, 0, SEEK_SET); 
    truncate("sorting_times.csv", ftell(csv_file)); 
    sort_count--; 
}

   
    clock_t start, end;
   
 
    // Perform sorting and also calculating the time required
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(user_d->quick_sort_checkbox))) {
     
        start=clock();
        quick_sort_low(arr, 0, size);
        end=clock();
        sorting_times[0]=((double)(end-start))/CLOCKS_PER_SEC;

          start=clock();
        quick_sort_high(arr, 0, size);
        end=clock();
        sorting_times[1]=((double)(end-start))/CLOCKS_PER_SEC;
        
          start=clock();
        quick_sort_median(arr, 0, size);
        end=clock();
        sorting_times[2]=((double)(end-start))/CLOCKS_PER_SEC;
        
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(user_d->radix_sort_checkbox))) {
          start=clock();
        radix_sort(arr, size);
        end=clock();
        sorting_times[3]=((double)(end-start))/CLOCKS_PER_SEC;
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(user_d->insertion_sort_checkbox))) {
          start=clock();
        insertion_sort(arr, size);
        end=clock();
        sorting_times[4]=((double)(end-start))/CLOCKS_PER_SEC;
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(user_d->bubble_sort_checkbox))) {
          start=clock();
        bubble_sort(arr, size);
        end=clock();
        sorting_times[5]=((double)(end-start))/CLOCKS_PER_SEC;
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(user_d->merge_sort_checkbox))) {
          start=clock();
        merge_sort(arr, 0, size - 1);
        end=clock();
        sorting_times[6]=((double)(end-start))/CLOCKS_PER_SEC;
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(user_d->heap_sort_checkbox))) {
          start=clock();
        heap_sort(arr, size);
        end=clock();
        sorting_times[7]=((double)(end-start))/CLOCKS_PER_SEC;
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(user_d->shell_sort_checkbox))) {
          start=clock();
        shell_sort(arr, size);
        end=clock();
        sorting_times[8]=((double)(end-start))/CLOCKS_PER_SEC;
    }
    fprintf(csv_file, "%d,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",size, sorting_times[0], sorting_times[1], sorting_times[2], sorting_times[3], sorting_times[4], sorting_times[5], sorting_times[6],sorting_times[7],sorting_times[8]);

 fclose(csv_file);
  
    free(arr);
}
void plot_callback(GtkWidget *widget, gpointer data) {
  
    FILE *fp = fopen("sorting_times.csv", "r+");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

   
    Row rows[100]; 
    int i = 0;
    char line[1024];
    while (fgets(line, 1024, fp)) {
        sscanf(line, "%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
               &rows[i].id, &rows[i].val1, &rows[i].val2, &rows[i].val3,
               &rows[i].val4, &rows[i].val5, &rows[i].val6, &rows[i].val7,&rows[i].val8,&rows[i].val9);
        i++;
    }

    // Sort the array of Row 
    qsort(rows, i, sizeof(Row), compareRows);

    rewind(fp);

   
    for (int j = 0; j < i; j++) {
        fprintf(fp, "%d,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",
                rows[j].id, rows[j].val1, rows[j].val2, rows[j].val3,
                rows[j].val4, rows[j].val5, rows[j].val6, rows[j].val7,rows[j].val8,rows[j].val9);
    }

    fclose(fp);

    // Plot the sorted data using gnuplot
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    if (!gnuplot) {
        perror("Error opening gnuplot");
        return;
    }

    fprintf(gnuplot, "set datafile separator ','\n");
    fprintf(gnuplot, "set title 'Sorting Algorithms Time Comparison by Input Size'\n");
    fprintf(gnuplot, "set xlabel 'Input Size (chunks)'\n");
    fprintf(gnuplot, "set ylabel 'Time (seconds)'\n");
    fprintf(gnuplot, "plot 'sorting_times.csv' using 1:2 title 'Quick Sort(LOW)' with lines, \\\n");
    fprintf(gnuplot, "     'sorting_times.csv' using 1:3 title 'Quick Sort(HIGH)' with lines, \\\n");
    fprintf(gnuplot, "     'sorting_times.csv' using 1:4 title 'Quick Sort(MEDIAN)' with lines, \\\n");
    fprintf(gnuplot, "     'sorting_times.csv' using 1:5 title 'Radix Sort' with lines, \\\n");
    fprintf(gnuplot, "     'sorting_times.csv' using 1:6 title 'Insertion Sort' with lines, \\\n");
    fprintf(gnuplot, "     'sorting_times.csv' using 1:7 title 'Bubble Sort' with lines, \\\n");
    fprintf(gnuplot, "     'sorting_times.csv' using 1:8 title 'Merge Sort' with lines, \\\n");
    fprintf(gnuplot, "     'sorting_times.csv' using 1:9 title 'Heap Sort' with lines, \\\n");
    fprintf(gnuplot, "     'sorting_times.csv' using 1:10 title 'Shell Sort' with lines\n");

    pclose(gnuplot);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = create_ui();
    gtk_widget_show(window);

    gtk_main();

    return 0;
}