#include <stdio.h>
#include <gtk/gtk.h>




static void activate(GtkApplication *app,gpointer user_data) {
    //Init of windowBurger
    GtkWidget *windowBurger = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(windowBurger),"BurgerClicker");
    gtk_window_present(GTK_WINDOW(windowBurger));

    //Init of gridParent
    GtkWidget *gridParent = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(windowBurger),gridParent);
}



int main(int argc, char **argv){
    FILE *file = fopen("filePath.txt","a");
    fclose(file);
    GtkApplication *app;
    int status;
    app= gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}