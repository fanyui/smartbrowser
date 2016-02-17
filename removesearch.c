#include<gtk/gtk.h>
#include<webkit/webkit.h>
#include "removesearch.h"
 extern const char* uri;
  extern GtkWidget *web;
void search(GtkWidget* widget, gpointer* wid)
{
GtkWidget* entry = GTK_WIDGET(wid);
uri = gtk_entry_get_text(GTK_ENTRY(entry));
gtk_entry_progress_pulse(GTK_ENTRY(entry));
webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web),uri);
 
}
 void remove_page (GtkButton *button,GtkWidget *notebook){//FUNCTION TO REMOVE A PAGE FROM THE NOTEBOOK
	gint index=gtk_notebook_get_current_page(GTK_NOTEBOOK(notebook));
	if (index==0)
	printf("can not remove page");
	else {
		gtk_notebook_remove_page(GTK_NOTEBOOK(notebook),index);
		gtk_widget_queue_draw (notebook);//TO REARRANGE AFTER REMOVING A PAGE
	}
}
//credite credential function
//credit function details not yet working the way it suppose to have to implement it using menus
 void credit_details(GtkButton *button, GtkNotebook *parent){
GtkWidget *dialog;
GdkPixbuf *logo;
GError *error = NULL;
const gchar *authors[] = {
"Author #1 Harisu fanyui",
NULL
};
const gchar *documenters[] = {
"Documenter #1 Harisu fanyui",
NULL
};
dialog = gtk_about_dialog_new();
logo = gdk_pixbuf_new_from_file ("logo.jpg", &error);


if (error == NULL)
gtk_about_dialog_set_logo (GTK_ABOUT_DIALOG (dialog), logo);
else
{
if (error->domain == GDK_PIXBUF_ERROR)
g_print ("GdkPixbufError: %s\n", error->message);
else if (error->domain == G_FILE_ERROR)
g_print ("GFileError: %s\n", error->message);
else
g_print ("An error in the domain: %d has occurred!\n", error->domain);
g_error_free (error);
}

/* Set application data that will be displayed in the main dialog. */
gtk_about_dialog_set_name (GTK_ABOUT_DIALOG (dialog), "smart browser version");
gtk_about_dialog_set_version (GTK_ABOUT_DIALOG (dialog), "1.0");
gtk_about_dialog_set_copyright (GTK_ABOUT_DIALOG (dialog),"(C) 2015 harisu fanyui");

gtk_about_dialog_set_comments (GTK_ABOUT_DIALOG (dialog),
"smartguy production");

/* Set the license text, which is usually loaded from a file. Also, set the
* web site address and label. */
gtk_about_dialog_set_license (GTK_ABOUT_DIALOG (dialog), "Free to all i mean everyone!");
//gtk_about_dialog_set_website (GTK_ABOUT_DIALOG (dialog),"http://techgate.com");
//gtk_about_dialog_set_website_label (GTK_ABOUT_DIALOG (dialog),"techgate.com");

/* Set the application authors, documenters and translators. */
gtk_about_dialog_set_authors (GTK_ABOUT_DIALOG (dialog), authors);
gtk_about_dialog_set_documenters (GTK_ABOUT_DIALOG (dialog), documenters);
gtk_about_dialog_set_translator_credits (GTK_ABOUT_DIALOG (dialog),"Translator #1 harisu fanyui\nTranslator #2");

gtk_dialog_run (GTK_DIALOG (dialog));
gtk_widget_destroy (dialog);
}

//home button function
void home(GtkWidget *hm,GtkNotebook *notebook){

gtk_notebook_set_current_page (notebook,0);

}
//the go back button
void back(GtkWidget* widget, gpointer* wid)
{
GtkWidget* web = GTK_WIDGET(wid);
webkit_web_view_go_back(WEBKIT_WEB_VIEW(web));
 
}

 void opendownload(GtkButton *button,GtkWidget *parent){
GtkWidget *dialog;
gchar *filename;
gint result;
dialog = gtk_file_chooser_dialog_new ("Create a Folder ...", NULL,GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,GTK_STOCK_OK, GTK_RESPONSE_OK,NULL);
result = gtk_dialog_run (GTK_DIALOG (dialog));
if (result == GTK_RESPONSE_OK)
{
filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
g_print ("Creating directory: %s\n", filename);
}
gtk_widget_destroy (dialog);
}




