#include <gtk/gtk.h>
#include<webkit/webkit.h>
#include "removesearch.h"
#include "add_page.h"
static void photobrows(GtkWidget *widget,GtkWidget *action);
static void destroy (GtkWidget *window,gpointer data);
static gboolean delete_event (GtkWidget *window,GdkEvent *event,gpointer data);
//static void opendownload(GtkButton *button,GtkWidget *parent);
 const char* uri;
 GtkWidget *web;
typedef struct {
GtkWidget *new1,*new2,*new3,*new4,*new5,*new6,*new7;
}Webaddress;


int main (int argc,char *argv[])
{
Webaddress *socialWebaddress = g_slice_new (Webaddress);
  socialWebaddress->new1= gtk_entry_new();
gtk_entry_set_text (GTK_ENTRY(socialWebaddress->new1),"http://www.facebook.com");
socialWebaddress->new2= gtk_entry_new ();
gtk_entry_set_text (GTK_ENTRY(socialWebaddress->new2),"http://www.gmail.com.com");
socialWebaddress->new3= gtk_entry_new ();
gtk_entry_set_text (GTK_ENTRY(socialWebaddress->new3),"http://www.twitter.com");
socialWebaddress->new4= gtk_entry_new();
gtk_entry_set_text (GTK_ENTRY(socialWebaddress->new4),"http://www.youtube.com");
socialWebaddress->new5= gtk_entry_new();
gtk_entry_set_text (GTK_ENTRY(socialWebaddress->new5),"http://www.skype.com");
socialWebaddress->new6= gtk_entry_new();
gtk_entry_set_text (GTK_ENTRY(socialWebaddress->new6),"http://www.chrome.com");


//gchar *loop="http://google.com";
GtkWidget *facebook,*gmail,*twitter,*chrome,*utube,*skype;
GtkWidget *photo,*socialPhoto,*socialPhoto1,*socialPhoto2,*socialPhoto3,*socialPhoto4,*socialPhoto5;
GtkWidget *window,*scrolled_win;//scrolled win not used
GtkWidget *notebook;
GtkWidget *child1, *child2,*child3;//used in creating the newtab,- and + for the tab
GtkWidget *hbox,*vbox;
GtkWidget *entry1,*entry2,*entry3;
GtkWidget *button1,*button2,*button3;
GtkWidget *label1,*label2;
GtkWidget *tempvbox1,*tempvbox2,*temphbox1,*temphbox2;	//temporal boxes to hold content of the main hbox that will go into the window container
GtkWidget *downloadbut,*homebut;//download and home button
GtkWidget *stock1,*stock2,*stock3;//to hold the stock image for download  home and back button
GtkWidget *showtext,*backbut;
backbut=gtk_button_new();
downloadbut=gtk_button_new();
homebut=gtk_button_new();

scrolled_win=gtk_scrolled_window_new(NULL,NULL);
gtk_container_set_border_width (GTK_CONTAINER (scrolled_win), 10);
gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_win),GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);

//social buttons

facebook=gtk_button_new();
gmail=gtk_button_new();
twitter=gtk_button_new();
skype=gtk_button_new();
chrome=gtk_button_new();
utube=gtk_button_new();

gtk_button_set_relief(GTK_BUTTON(backbut),GTK_RELIEF_NONE);
gtk_button_set_relief(GTK_BUTTON(downloadbut),GTK_RELIEF_NONE);
gtk_button_set_relief(GTK_BUTTON(homebut),GTK_RELIEF_NONE);
//social media
gtk_button_set_relief(GTK_BUTTON(facebook),GTK_RELIEF_NONE);
gtk_button_set_relief(GTK_BUTTON(gmail),GTK_RELIEF_NONE);
gtk_button_set_relief(GTK_BUTTON(twitter),GTK_RELIEF_NONE);
gtk_button_set_relief(GTK_BUTTON(chrome),GTK_RELIEF_NONE);
gtk_button_set_relief(GTK_BUTTON(utube),GTK_RELIEF_NONE);
gtk_button_set_relief(GTK_BUTTON(skype),GTK_RELIEF_NONE);
//signals on the social media photos
g_signal_connect(G_OBJECT(facebook),"clicked",G_CALLBACK(search),socialWebaddress->new1);
g_signal_connect(G_OBJECT(gmail),"clicked",G_CALLBACK(search),socialWebaddress->new2);
g_signal_connect(G_OBJECT(twitter),"clicked",G_CALLBACK(search),socialWebaddress->new3);
g_signal_connect(G_OBJECT(skype),"clicked",G_CALLBACK(search),socialWebaddress->new4);
g_signal_connect(G_OBJECT(chrome),"clicked",G_CALLBACK(search),socialWebaddress->new5);
g_signal_connect(G_OBJECT(utube),"clicked",G_CALLBACK(search),socialWebaddress->new6);
//the window production begins 
gtk_init (&argc, &argv);
window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
gtk_window_set_title (GTK_WINDOW (window), "SMART BROWSER!!!!!");
gtk_container_set_border_width (GTK_CONTAINER (window), 20);
gtk_widget_set_size_request (window, 1200, 600);
//Connect the main window to the destroy and delete-event signals. 
g_signal_connect (G_OBJECT (window), "destroy",G_CALLBACK (destroy), NULL);
//end of producing the main window
vbox=gtk_vbox_new(FALSE,0);//main vbox that will go into the main window container
notebook=gtk_notebook_new();//CREATING A NEW NOTEBOOK

hbox=gtk_hbox_new(FALSE,0);
gtk_widget_set_size_request(hbox,150,20);
child1=gtk_label_new("newtab");
child2=gtk_button_new_with_label("-");
child3=gtk_button_new_with_label("+");
//REDUCING THE SIZE OF THE BUTTONS
gtk_button_set_relief(GTK_BUTTON(child2),GTK_RELIEF_NONE);
gtk_button_set_relief(GTK_BUTTON(child3),GTK_RELIEF_NONE);
//CONNECTING THE SIGNALS OF THE BUTTONS
g_signal_connect(G_OBJECT(child2),"clicked",G_CALLBACK(remove_page),(gpointer)notebook);
g_signal_connect(G_OBJECT(child3),"clicked",G_CALLBACK(add_page),(gpointer)notebook);
//PACKING THE BUTTON INTO THE HBOX
gtk_box_pack_start(GTK_BOX(hbox),child1,TRUE,TRUE,4);
gtk_box_pack_start(GTK_BOX(hbox),child2,FALSE,FALSE,0);
gtk_box_pack_start(GTK_BOX(hbox),child3,FALSE,FALSE,0);
gtk_widget_show_all(hbox);

//START OF PRODUCING THE CONTENT OF THE PAGE
tempvbox1=gtk_vbox_new(FALSE,0);//VBOX TO PACK THE VARIOUS CONTENT OF THE NOTEBOOK PAGE
//producing the content of the new page that will be created by this fuction 


 stock1=gtk_image_new_from_stock (GTK_STOCK_HOME,5);
gtk_container_add(GTK_CONTAINER(homebut),stock1);
//stock1=gtk_button_new_from_stock(GTK_STOCK_MEDIA_NEXT);
 stock2= gtk_image_new_from_stock (GTK_STOCK_GO_DOWN,5);

gtk_container_add(GTK_CONTAINER(downloadbut),stock2);
stock3=gtk_image_new_from_stock (GTK_STOCK_GO_BACK,5);
gtk_container_add(GTK_CONTAINER(backbut),stock3);
entry1 = gtk_entry_new ();//entry for typing address
gtk_widget_set_size_request(entry1,450,30);
entry2=gtk_entry_new();//entry for the search engine
button1 = gtk_button_new_with_label("Search:");
button2 = gtk_button_new_with_label("CREDIT:");
photo =gtk_button_new_with_label("search by photo");
//REDUCING THE SIZE OF THE BUTTON 
gtk_button_set_relief(GTK_BUTTON(button1),GTK_RELIEF_NONE);
gtk_button_set_relief(GTK_BUTTON(button2),GTK_RELIEF_NONE);

g_signal_connect(G_OBJECT(entry1),"activate",G_CALLBACK(search),entry1);//so that we cann connect with only pressing enter key from the keyboard
g_signal_connect(G_OBJECT(button1),"clicked",G_CALLBACK(search),entry1);
g_signal_connect(G_OBJECT(button2),"clicked",G_CALLBACK(credit_details),(gpointer)notebook);
g_signal_connect(G_OBJECT(homebut),"clicked",G_CALLBACK(home),(gpointer)notebook);
g_signal_connect(G_OBJECT(downloadbut),"clicked",G_CALLBACK(opendownload),(gpointer)window);
g_signal_connect(G_OBJECT(photo),"clicked",G_CALLBACK(photobrows),NULL);

 	/* WORKING ON THE VISIBILITY OF THE GtkEntry widget */
gtk_entry_set_text(GTK_ENTRY(entry2),"let's go to the new world");
gtk_entry_set_visibility (GTK_ENTRY (entry2), TRUE);
gtk_entry_set_text(GTK_ENTRY(entry1),"http://");
gtk_entry_set_visibility (GTK_ENTRY (entry1), TRUE);

temphbox1 = gtk_hbox_new (FALSE, 0);//HBOX TO PACK THE CREATED ENTRY AND BUTTONS SO THAT IT WILL FINALLY BE PACKED INTO ADDVBOX
gtk_box_pack_start(GTK_BOX (temphbox1),backbut,FALSE,FALSE,0);
gtk_box_pack_start(GTK_BOX (temphbox1), entry1,TRUE,TRUE,1);
gtk_box_pack_start(GTK_BOX (temphbox1), button1,TRUE,TRUE,0);

gtk_box_pack_start(GTK_BOX (temphbox1), entry2,TRUE,TRUE,0);
gtk_box_pack_start(GTK_BOX (temphbox1), button2,TRUE,TRUE,0);
gtk_box_pack_start(GTK_BOX(temphbox1),homebut,TRUE,TRUE,0);
gtk_box_pack_start(GTK_BOX(temphbox1),downloadbut,TRUE,TRUE,0);
gtk_box_pack_start(GTK_BOX(temphbox1),photo,TRUE,TRUE,0);
gtk_widget_show_all(temphbox1);
gtk_box_pack_start(GTK_BOX (tempvbox1), temphbox1,FALSE,FALSE,0);
//another box to pack the photo of the default page
temphbox2=gtk_hbox_new(TRUE,0);//new box to pack another thing that will go into the main box of the window
gtk_widget_set_size_request(temphbox2,150,200);
GtkWidget *picture=gtk_image_new_from_file ("logo.jpg");
gtk_box_pack_start(GTK_BOX(temphbox2),picture,TRUE,TRUE,0);
gtk_widget_show_all(picture);
gtk_box_pack_start(GTK_BOX(tempvbox1),temphbox2,TRUE,TRUE,0);



//creating another hbox to pack another entry and a button of search  smaller this timearound
temphbox2=gtk_hbox_new(FALSE,0);//new box to pack another thing that will go into the main box of the window
button3=gtk_button_new_with_label("search");


showtext=gtk_label_new("ENJOY THE POWER OF SMART SEARCH");//empty label to adjust the text  entry in the middle of the screen
gtk_box_pack_start(GTK_BOX(temphbox2),showtext,TRUE,FALSE,0);
gtk_button_set_relief(GTK_BUTTON(button3),GTK_RELIEF_NONE);
entry3= gtk_entry_new ();

gtk_widget_set_size_request(entry3,200,30);
gtk_entry_set_text(GTK_ENTRY(entry3),"bing");
gtk_entry_set_visibility (GTK_ENTRY (entry3), TRUE);
g_signal_connect(G_OBJECT(button3),"clicked",G_CALLBACK(search),entry3);
gtk_box_pack_start(GTK_BOX(temphbox2),entry3,TRUE,TRUE,0);
gtk_box_pack_start(GTK_BOX(temphbox2),button3,FALSE,FALSE,0);
showtext=gtk_label_new("");// to balance the search entry inthe center
gtk_box_pack_start(GTK_BOX(temphbox2),showtext,FALSE,FALSE,0);
gtk_widget_show_all(temphbox2);
gtk_box_pack_start(GTK_BOX(tempvbox1),temphbox2,TRUE,TRUE,0);
// another hbox to pack the webkit
temphbox1=gtk_hbox_new(TRUE,0);//new box to pack another thing that will go into the main box of the window;
web = webkit_web_view_new();
gtk_box_pack_start(GTK_BOX(temphbox1),web,TRUE,TRUE,1);
gtk_widget_show_all(web);
gtk_box_pack_start(GTK_BOX(tempvbox1),temphbox1,TRUE,TRUE,TRUE);
g_signal_connect(G_OBJECT(backbut),"clicked",G_CALLBACK(back),web);

//social pictures 
temphbox2=gtk_hbox_new(TRUE,0);//new box to pack another thing that will go into the main box of the window
//gtk_widget_set_size_request(temphbox2,150,200);
socialPhoto=gtk_image_new_from_file ("Images/utube.jpg");
gtk_container_add(GTK_CONTAINER(skype),socialPhoto);
gtk_box_pack_start(GTK_BOX(temphbox2),skype,TRUE,TRUE,0);



socialPhoto1=gtk_image_new_from_file ("Images/facebook.jpg");
gtk_container_add(GTK_CONTAINER(facebook),socialPhoto1);
gtk_box_pack_start(GTK_BOX(temphbox2),facebook,FALSE,FALSE,0);
socialPhoto2=gtk_image_new_from_file ("Images/gmail.jpg");
gtk_container_add(GTK_CONTAINER(gmail),socialPhoto2);
gtk_box_pack_start(GTK_BOX(temphbox2),gmail,FALSE,FALSE,0);
socialPhoto3=gtk_image_new_from_file ("Images/twitter.jpg");
gtk_container_add(GTK_CONTAINER(twitter),socialPhoto3);
gtk_box_pack_start(GTK_BOX(temphbox2),twitter,FALSE,FALSE,0);
socialPhoto4=gtk_image_new_from_file ("Images/chrome.jpg");
gtk_container_add(GTK_CONTAINER(utube),socialPhoto4);
gtk_box_pack_start(GTK_BOX(temphbox2),utube,FALSE,FALSE,0);
socialPhoto5=gtk_image_new_from_file ("Images/skype.jpg");
gtk_container_add(GTK_CONTAINER(chrome),socialPhoto5);
gtk_box_pack_start(GTK_BOX(temphbox2),chrome,TRUE,TRUE,0);
gtk_box_pack_start(GTK_BOX(tempvbox1),temphbox2,FALSE,FALSE,0);
//gtk_widget_show_all(socialPhoto);
gtk_widget_show_all(temphbox2);

//START OF APPENDING PAGES TO THE NOTEBOOK
gtk_notebook_append_page(GTK_NOTEBOOK(notebook),tempvbox1,hbox);
gtk_box_pack_start(GTK_BOX(vbox),notebook,FALSE,FALSE,0);//PACKING THE NOTEBOOK INTO THE  MAIN VBOX
//gtk_container_add(GTK_CONTAINER(scrolled_win),vbox);
gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW (scrolled_win),vbox);
gtk_container_add(GTK_CONTAINER(window),scrolled_win);
gtk_widget_show_all(window);
gtk_main ();
return 0;
}
static void destroy (GtkWidget *window,gpointer data){
gtk_main_quit ();
}
static gboolean delete_event (GtkWidget *window,GdkEvent *event,gpointer data){//FUNCTION TO QUITE NOT USED
return FALSE;
}
static void photobrows(GtkWidget *widget,GtkWidget *action){
GtkWidget *dialog;
gchar *filename;
gint result;
/* Create a new GtkFileChooserDialog that will be used to create a new folder. */
dialog = gtk_file_chooser_dialog_new ("select a photo and search with it ...", NULL,GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,GTK_STOCK_OK, GTK_RESPONSE_OK,NULL);
result = gtk_dialog_run (GTK_DIALOG (dialog));
if (result == GTK_RESPONSE_OK)
{
filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
g_print ("photo selected: %s\n", filename);
}
gtk_widget_destroy (dialog);
}
 

 




