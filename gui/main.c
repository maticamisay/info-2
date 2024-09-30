#include <gtk/gtk.h>

// Función para manejar el cierre de la ventana
static void on_close_button_clicked(GtkWidget *widget, gpointer data)
{
    g_print("¡Cerrar caja clickeado!\n");
    gtk_main_quit(); // Cierra la aplicación
}

// Cargar y aplicar el archivo CSS
void apply_css(GtkWidget *widget)
{
    GtkCssProvider *provider = gtk_css_provider_new();
    GdkDisplay *display = gdk_display_get_default();
    GdkScreen *screen = gdk_display_get_default_screen(display);

    // Cargar el archivo CSS
    gtk_css_provider_load_from_path(provider, "styles.css", NULL);

    // Aplicar el estilo a todos los widgets
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
}

// Crea una "card" con la información proporcionada
GtkWidget *create_card(const char *title, const char *info1, const char *info2, const char *info3)
{
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    GtkWidget *label_title = gtk_label_new(title);
    GtkWidget *label_info1 = gtk_label_new(info1);
    GtkWidget *label_info2 = gtk_label_new(info2);
    GtkWidget *label_info3 = gtk_label_new(info3);

    gtk_box_pack_start(GTK_BOX(box), label_title, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label_info1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label_info2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label_info3, FALSE, FALSE, 0);

    // Aplicar estilo de card
    GtkStyleContext *context = gtk_widget_get_style_context(box);
    gtk_style_context_add_class(context, "card");

    return box;
}

// Crea un botón con estilo usando gtk_widget_set_name
GtkWidget *create_styled_button(const char *label_text)
{
    GtkWidget *button = gtk_button_new_with_label(label_text);

    // Asignar una clase CSS al botón
    GtkStyleContext *context = gtk_widget_get_style_context(button);
    gtk_style_context_add_class(context, "buttonBlue");

    return button;
}

int main(int argc, char *argv[])
{
    // Inicializa GTK
    gtk_init(&argc, &argv);

    // Crear la ventana
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Caja y Dólar Hoy");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Crear un contenedor horizontal
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_container_add(GTK_CONTAINER(window), hbox);

    // Sección 1: Card "Caja"
    GtkWidget *card_caja = create_card("Caja",
                                       "Dinero inicial de caja: $100.000",
                                       "Balance generado: $45.500",
                                       "Facturación del día: $50.000");

    GtkWidget *close_button = gtk_button_new_with_label("Cerrar caja");
    g_signal_connect(close_button, "clicked", G_CALLBACK(on_close_button_clicked), NULL);

    // Crear caja vertical para agrupar el card y el botón "Cerrar caja"
    GtkWidget *vbox_caja = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(vbox_caja), card_caja, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox_caja), close_button, FALSE, FALSE, 0);

    // Sección 2: Card "Dólar hoy"
    GtkWidget *card_dolar = create_card("Dólar hoy",
                                        "Blue Compra: $821.66 - Venta: $880.57",
                                        "Oficial Compra: $821.66",
                                        "Oficial Venta: $880.57");

    // Sección 3: Botones de acciones
    GtkWidget *button_cuenta_corriente = create_styled_button("Cobrar cuenta corriente\nCTRL + ALT + C");
    GtkWidget *button_nuevo_comprobante = create_styled_button("Nuevo comprobante\nCTRL + ALT + A");
    GtkWidget *button_nuevo_pedido = create_styled_button("Nuevo pedido\nCTRL + ALT + P");
    GtkWidget *button_agregar_producto = create_styled_button("Agregar producto\nCTRL + ALT + A");

    // Crear caja vertical para los botones
    GtkWidget *vbox_botones = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(vbox_botones), button_cuenta_corriente, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox_botones), button_nuevo_comprobante, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox_botones), button_nuevo_pedido, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox_botones), button_agregar_producto, TRUE, TRUE, 0);

    // Añadir las 3 secciones al contenedor horizontal (hbox)
    gtk_box_pack_start(GTK_BOX(hbox), vbox_caja, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), card_dolar, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), vbox_botones, TRUE, TRUE, 0);

    // Aplicar el CSS
    apply_css(window);
    
    // Mostrar todo
    gtk_widget_show_all(window);

    // Ejecuta el bucle principal de GTK
    gtk_main();

    return 0;
}