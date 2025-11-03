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

    //Init of labelBurgerNormal
    GtkWidget *labelBurgerNormal = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(gridParent),labelBurgerNormal,3,5,5,5);
    gtk_widget_add_css_class(labelBurgerNormal,"labelBurgerNormal");

    //Init of labelBurgerRare
    GtkWidget *labelBurgerRare = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(gridParent),labelBurgerRare,3,5,5,5);
    gtk_widget_add_css_class(labelBurgerRare,"labelBurgerRare");

    //Init of labelBurgerEpic
    GtkWidget *labelBurgerEpic = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(gridParent),labelBurgerEpic,3,5,5,5);
    gtk_widget_add_css_class(labelBurgerEpic,"labelBurgerEpic");

    //Init of labelBurgerLegendary
    GtkWidget *labelBurgerLegendary = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(gridParent),labelBurgerLegendary,3,5,5,5);
    gtk_widget_add_css_class(labelBurgerLegendary,"labelBurgerLegendary");

    //Init of buttonBurger
    GtkWidget *buttonBurger = gtk_button_new_with_label("BUTTON BORGER");
    gtk_grid_attach(GTK_GRID(gridParent),buttonBurger,3,5,5,5);
    gtk_widget_add_css_class(buttonBurger,"buttonBurger");



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