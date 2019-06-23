
/*
objects here are like html divs. u have to create objects and then apply style to them. to apply styles, create a style object and then set the object's style. see the example below.
*/
void create_gui(void)
{
	/*Creating Chart*/

    /*Create a style*/
	static lv_style_t style_bg;
	static lv_style_t style_chart;
	static lv_style_t style_txt;

	//Style fr background
	style_bg.body.main_color = LV_COLOR_NAVY;
	style_bg.body.grad_color = LV_COLOR_NAVY;
	style_bg.body.opa = 255;
	style_bg.body.border.opa = LV_OPA_50;
	style_bg.text.color = LV_COLOR_RED;

	//Style for chart plot area
	style_chart.body.main_color = LV_COLOR_BLACK;
	style_chart.body.grad_color = LV_COLOR_BLACK;
	style_chart.body.opa = 255;
	style_chart.body.border.opa = LV_OPA_50;
	style_chart.text.color = LV_COLOR_WHITE;

    //Style for texts
    style_txt.text.font = &lv_font_dejavu_40;
    style_txt.text.letter_space = 2;
    style_txt.text.line_space = 1;
	style_txt.text.color = LV_COLOR_YELLOW;

	//Creating the background and chart
	lv_obj_t *bg = lv_obj_create(lv_scr_act(), NULL);  //bg is a new object
	lv_obj_set_style(bg, &style_bg);
	lv_obj_set_pos(bg, 0, 0);
	lv_obj_set_size(bg, 1000, 600);

	lv_obj_t *chart = lv_obj_create(lv_scr_act(), NULL); //chart is a new object
	lv_obj_set_style(chart, &style_chart);
	lv_obj_set_pos(chart, 100, 0);
	lv_obj_set_size(chart, 800, 570);

	lv_obj_t *footer_bg = lv_obj_create(lv_scr_act(), NULL); //chart is a new object
	lv_obj_set_style(footer_bg, &style_chart);
	lv_obj_set_pos(footer_bg, 0, 570);
	lv_obj_set_size(footer_bg, 1000, 30);

	/*lv_obj_t *domain = lv_obj_create(lv_scr_act(), NULL); //chart is a new object
	lv_obj_set_style(domain, &style_chart);
	lv_obj_set_pos(domain, 0, 0);
	lv_obj_set_size(domain, 1000, 50);*/

	lv_obj_t *txt = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(txt, "Channel 1");
    lv_obj_set_style(txt, &style_txt);
    lv_label_set_recolor(txt, true);



    /*================================================================*/

    /*Creating Channel Buttons*/
    lv_obj_t *btn1 = lv_btn_create(footer_bg, NULL);
    lv_obj_set_pos(btn1, 0, 0);
    lv_obj_set_size(btn1, 200, 30);
    lv_obj_t *label1 = lv_label_create(btn1, NULL);
    lv_label_set_text(label1, "Channel 1");

    lv_obj_t *btn2 = lv_btn_create(footer_bg, NULL);
    lv_obj_set_pos(btn2, 200, 0);
    lv_obj_set_size(btn2, 200, 30);
    lv_obj_t *label2 = lv_label_create(btn2, NULL);
    lv_label_set_text(label2, "Channel 2");

    lv_obj_t *btn3 = lv_btn_create(footer_bg, NULL);
    lv_obj_set_pos(btn3, 400, 0);
    lv_obj_set_size(btn3, 200, 30);
    lv_obj_t *label3 = lv_label_create(btn3, NULL);
    lv_label_set_text(label3, "Channel 3");

    lv_obj_t *btn4 = lv_btn_create(footer_bg, NULL);
    lv_obj_set_pos(btn4, 600, 0);
    lv_obj_set_size(btn4, 200, 30);
    lv_obj_t *label4 = lv_label_create(btn4, NULL);
    lv_label_set_text(label4, "Channel 4");

    /*================================================================*/
    /*Create a buffer for the canvas set its pixels to light blue*/
    static lv_color_t cbuf[sizeof(lv_color_t) * 640 * 480];
    uint32_t i;
    for(i = 0; i < sizeof(cbuf) / sizeof(cbuf[0]); i++) {
        cbuf[i] = LV_COLOR_HEX3(0x000);
    }

    /*Create the canvas object*/
    lv_obj_t * canvas = lv_canvas_create(lv_scr_act(), NULL);
    lv_obj_set_pos(canvas, 100, 0);
    /*Assign the buffer to the canvas*/
    lv_canvas_set_buffer(canvas, cbuf, 800, 570, LV_IMG_CF_TRUE_COLOR);

    /*Set some pixels*/
    lv_canvas_set_px(canvas, 100,100, LV_COLOR_RED);
    lv_canvas_set_px(canvas, 2,5, LV_COLOR_BLUE);



}
