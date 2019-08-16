#define EXTRA_KEYWORDS "custom_keywords.h"
#include "4coder_default_include.cpp"

void custom_keys(Bind_Helper *context){
    
    begin_map(context, mapid_global); {
        bind(context, 'p', MDFR_CTRL, open_panel_vsplit );
        bind(context, 'p', MDFR_ALT, close_panel);
		bind(context, 'w', MDFR_CTRL, change_active_panel);

    } end_map(context);
    
    begin_map(context, mapid_file); {
        bind_vanilla_keys(context, write_character);
		bind(context, 'e', MDFR_ALT, seek_end_of_line);
		bind(context, 'r', MDFR_CTRL, replace_in_range);
		bind(context, 'a', MDFR_CTRL, seek_beginning_of_line);
        bind(context, 'a', MDFR_ALT, replace_in_range);


    } end_map(context);
    
    begin_map(context, default_code_map); {
        inherit_map(context, mapid_file);
        bind(context, key_right, MDFR_CTRL, seek_alphanumeric_or_camel_right);

    } end_map(context);

    begin_map(context, default_lister_ui_map); {
        bind_vanilla_keys(context, lister__write_character);
        bind(context, key_esc, MDFR_NONE, lister__quit);
        bind(context, '\n', MDFR_NONE, lister__activate);
        bind(context, '\t', MDFR_NONE, lister__activate);
        bind(context, key_back, MDFR_NONE, lister__backspace_text_field);
        bind(context, key_up, MDFR_NONE, lister__move_up);
        bind(context, key_page_up, MDFR_NONE, lister__move_up);
        bind(context, key_down, MDFR_NONE, lister__move_down);
        bind(context, key_page_down, MDFR_NONE, lister__move_down);
        bind(context, key_mouse_wheel, MDFR_NONE, lister__wheel_scroll);
        bind(context, key_mouse_left, MDFR_NONE, lister__mouse_press);
        bind(context, key_mouse_left_release, MDFR_NONE, lister__mouse_release);
        bind(context, key_mouse_move, MDFR_NONE, lister__repaint);
        bind(context, key_animate, MDFR_NONE, lister__repaint);
    } end_map(context);
}

extern "C" int32_t
get_bindings(void *data, int32_t size){
    Bind_Helper context_ = begin_bind_helper(data, size);
    Bind_Helper *context = &context_;
    
    set_all_default_hooks(context);
    
	default_keys(context);
    custom_keys(context);

    
    int32_t result = end_bind_helper(context);
    return(result);
}