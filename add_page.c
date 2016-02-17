#include<gtk/gtk.h>
#include "removesearch.h"
 extern const char* uri;
 extern GtkWidget *web;
 void add_page(GtkButton *button,GtkWidget *notebook){//TO ADD A NEW PAGE TO THE  NOTEBOOK
GtkWidget *addLabel,*newhbox,*addvbox;
GtkWidget *newbutton,*newbutton1,*newbutton2,*newbutton3;
GtkWidget *newchild1,*newchild2,*newchild3;
GtkWidget *entry1,*entry2;//entry widgets
GtkWidget *label,*label1,*label2;
GtkWidget *envbox, *enhbox,*enhbox1, *question;
GtkWidget *stock1,*stock2,*downloadbut,*homebut,*scrolled_win,*backbut,*stock3;
GtkTextBuffer *buffer;
GtkWidget *photo;

backbut=gtk_button_new();
downloadbut=gtk_button_new();
homebut=gtk_button_new();
gtk_button_set_relief(GTK_BUTTON(downloadbut),GTK_RELIEF_NONE);
gtk_button_set_relief(GTK_BUTTON(homebut),GTK_RELIEF_NONE);

gint index=gtk_notebook_get_current_page(GTK_NOTEBOOK(notebook));
//here we are producing the content of the tab label
newhbox=gtk_hbox_new(FALSE,0);
label=gtk_label_new("newtab");
gtk_box_pack_start(GTK_BOX(newhbox),label,TRUE,TRUE,4);
newbutton=gtk_button_new_with_label("-");
gtk_button_set_relief(GTK_BUTTON(newbutton),GTK_RELIEF_NONE);
g_signal_connect(G_OBJECT(newbutton),"clicked",G_CALLBACK(remove_page),(gpointer)notebook);
gtk_box_pack_start(GTK_BOX(newhbox),newbutton,FALSE,FALSE,0);
newbutton1=gtk_button_new_with_label("+");
gtk_button_set_relief(GTK_BUTTON(newbutton1),GTK_RELIEF_NONE);
g_signal_connect(G_OBJECT(newbutton1),"clicked",G_CALLBACK(add_page),(gpointer)notebook);
gtk_box_pack_start(GTK_BOX(newhbox),newbutton1,FALSE,FALSE,0);
gtk_widget_show_all(newhbox);

addvbox=gtk_vbox_new(FALSE,1);//to contain all other hboxes

//producing the content of the new page that will be created by this fuction 
enhbox = gtk_hbox_new (FALSE, 0);//HBOX TO PACK THE CREATED ENTRY AND BUTTONS SO THAT IT WILL FINALLY BE PACKED INTO ADDVBOX
 stock1=gtk_image_new_from_stock (GTK_STOCK_HOME,5);
gtk_container_add(GTK_CONTAINER(homebut),stock1);
//stock1=gtk_button_new_from_stock(GTK_STOCK_MEDIA_NEXT);
 stock2= gtk_image_new_from_stock (GTK_STOCK_GO_DOWN,5);
gtk_container_add(GTK_CONTAINER(downloadbut),stock2);

 stock3= gtk_image_new_from_stock (GTK_STOCK_GO_BACK,5);
gtk_container_add(GTK_CONTAINER(backbut),stock3);
entry1 = gtk_entry_new ();
gtk_widget_set_size_request(entry1,450,30);
entry2=gtk_entry_new();
newbutton1 = gtk_button_new_with_label("Search:");
newbutton2= gtk_button_new_with_label("Engine:");
photo=gtk_button_new_with_label("search by photo");
//REDUCING THE SIZE OF THE BUTTON 
gtk_button_set_relief(GTK_BUTTON(newbutton1),GTK_RELIEF_NONE);
gtk_button_set_relief(GTK_BUTTON(newbutton2),GTK_RELIEF_NONE);
//CONNECTING THE SIGNAL OF THE  ENTRY BUTTON 

g_signal_connect(G_OBJECT(entry1),"activate",G_CALLBACK(search),entry1);
g_signal_connect(G_OBJECT(newbutton1),"clicked",G_CALLBACK(search),entry1);
g_signal_connect(G_OBJECT(homebut),"clicked",G_CALLBACK(home),(gpointer)notebook);
g_signal_connect(G_OBJECT(downloadbut),"clicked",G_CALLBACK(opendownload),(gpointer)notebook);

 	/* WORKING ON THE VISIBILITY OF THE GtkEntry widget */
gtk_entry_set_text(GTK_ENTRY(entry2),"bing");
gtk_entry_set_visibility (GTK_ENTRY (entry2), TRUE);
gtk_entry_set_text(GTK_ENTRY(entry1),"http://");
gtk_entry_set_visibility (GTK_ENTRY (entry1), TRUE);
//start of the packing
gtk_box_pack_start(GTK_BOX (enhbox), backbut,FALSE,FALSE,0);
gtk_box_pack_start(GTK_BOX (enhbox), entry1,TRUE,TRUE,1);
gtk_box_pack_start(GTK_BOX (enhbox), newbutton1,FALSE,FALSE,0);

gtk_box_pack_start(GTK_BOX (enhbox), entry2,TRUE,TRUE,1);
gtk_box_pack_start(GTK_BOX (enhbox), newbutton2,FALSE,FALSE,0);
gtk_box_pack_start(GTK_BOX(enhbox),homebut,FALSE,FALSE,0);
gtk_box_pack_start(GTK_BOX(enhbox),downloadbut,FALSE,FALSE,0);
gtk_box_pack_start(GTK_BOX(enhbox),photo,FALSE,FALSE,0);
gtk_widget_show_all(enhbox);
gtk_box_pack_start(GTK_BOX (addvbox), enhbox,0,0,1);

//webkit
enhbox=gtk_hbox_new(TRUE,0);//new box to pack webkit that will go into the main box of the window;
web = webkit_web_view_new();
gtk_box_pack_start(GTK_BOX(enhbox),web,TRUE,TRUE,TRUE);
gtk_widget_show_all(enhbox);
//gtk_widget_show_all(web);
g_signal_connect(G_OBJECT(backbut),"clicked",G_CALLBACK(back),web);//to be able to go back to the previous page
gtk_box_pack_start(GTK_BOX(addvbox),enhbox,TRUE,TRUE,TRUE);


gtk_notebook_insert_page(GTK_NOTEBOOK(notebook),addvbox,newhbox,index+1);

gtk_notebook_set_scrollable(GTK_NOTEBOOK(notebook),TRUE);

gtk_widget_show_all(GTK_WIDGET(notebook));
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),index+1);
}




