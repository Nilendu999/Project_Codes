                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                istance_REPLACED_BY_cairo_user_to_device_distance
#define cairo_inverse_transform_point	 cairo_inverse_transform_point_REPLACED_BY_cairo_device_to_user
#define cairo_inverse_transform_distance cairo_inverse_transform_distance_REPLACED_BY_cairo_device_to_user_distance
#define cairo_init_clip			 cairo_init_clip_REPLACED_BY_cairo_reset_clip
#define cairo_surface_create_for_image	 cairo_surface_create_for_image_REPLACED_BY_cairo_image_surface_create_for_data
#define cairo_default_matrix		 cairo_default_matrix_REPLACED_BY_cairo_identity_matrix
#define cairo_matrix_set_affine		 cairo_matrix_set_affine_REPLACED_BY_cairo_matrix_init
#define cairo_matrix_set_identity	 cairo_matrix_set_identity_REPLACED_BY_cairo_matrix_init_identity
#define cairo_pattern_add_color_stop	 cairo_pattern_add_color_stop_REPLACED_BY_cairo_pattern_add_color_stop_rgba
#define cairo_set_rgb_color		 cairo_set_rgb_color_REPLACED_BY_cairo_set_source_rgb
#define cairo_set_pattern		 cairo_set_pattern_REPLACED_BY_cairo_set_source
#define cairo_xlib_surface_create_for_pixmap_with_visual	cairo_xlib_surface_create_for_pixmap_with_visual_REPLACED_BY_cairo_xlib_surface_create
#define cairo_xlib_surface_create_for_window_with_visual	cairo_xlib_surface_create_for_window_with_visual_REPLACED_BY_cairo_xlib_surface_create
#define cairo_xcb_surface_create_for_pixmap_with_visual	cairo_xcb_surface_create_for_pixmap_with_visual_REPLACED_BY_cairo_xcb_surface_create
#define cairo_xcb_surface_create_for_window_with_visual	cairo_xcb_surface_create_for_window_with_visual_REPLACED_BY_cairo_xcb_surface_create
#define cairo_ps_surface_set_dpi	cairo_ps_surface_set_dpi_REPLACED_BY_cairo_surface_set_fallback_resolution
#define cairo_pdf_surface_set_dpi	cairo_pdf_surface_set_dpi_REPLACED_BY_cairo_surface_set_fallback_resolution
#define cairo_svg_surface_set_dpi	cairo_svg_surface_set_dpi_REPLACED_BY_cairo_surface_set_fallback_resolution
#define cairo_atsui_font_face_create_for_atsu_font_id  cairo_atsui_font_face_create_for_atsu_font_id_REPLACED_BY_cairo_quartz_font_face_create_for_atsu_font_id

#define cairo_current_path	     cairo_current_path_DEPRECATED_BY_cairo_copy_path
#define cairo_current_path_flat	     cairo_current_path_flat_DEPRECATED_BY_cairo_copy_path_flat
#define cairo_get_path		     cairo_get_path_DEPRECATED_BY_cairo_copy_path
#define cairo_get_path_flat	     cairo_get_path_flat_DEPRECATED_BY_cairo_get_path_flat
#define cairo_set_alpha		     cairo_set_alpha_DEPRECATED_BY_cairo_set_source_rgba_OR_cairo_paint_with_alpha
#define cairo_show_surface	     cairo_show_surface_DEPRECATED_BY_cairo_set_source_surface_AND_cairo_paint
#define cairo_copy		     cairo_copy_DEPRECATED_BY_cairo_create_AND_MANY_INDIVIDUAL_FUNCTIONS
#define cairo_surface_set_repeat	cairo_surface_set_repeat_DEPRECATED_BY_cairo_pattern_set_extend
#define cairo_surface_set_matrix	cairo_surface_set_matrix_DEPRECATED_BY_cairo_pattern_set_matrix
#define cairo_surface_get_matrix	cairo_surface_get_matrix_DEPRECATED_BY_cairo_pattern_get_matrix
#define cairo_surface_set_filter	cairo_surface_set_filter_DEPRECATED_BY_cairo_pattern_set_filter
#define cairo_surface_get_filter	cairo_surface_get_filter_DEPRECATED_BY_cairo_pattern_get_filter
#define cairo_matrix_create		cairo_matrix_create_DEPRECATED_BY_cairo_matrix_t
#define cairo_matrix_destroy		cairo_matrix_destroy_DEPRECATED_BY_cairo_matrix_t
#define cairo_matrix_copy		cairo_matrix_copy_DEPRECATED_BY_cairo_matrix_t
#define cairo_matrix_get_affine		cairo_matrix_get_affine_DEPRECATED_BY_cairo_matrix_t
#define cairo_set_target_surface	cairo_set_target_surface_DEPRECATED_BY_cairo_create
#define cairo_set_target_image		cairo_set_target_image_DEPRECATED_BY_cairo_image_surface_create_for_data
#define cairo_set_target_pdf		cairo_set_target_pdf_DEPRECATED_BY_cairo_pdf_surface_create
#define cairo_set_target_png		cairo_set_target_png_DEPRECATED_BY_cairo_surface_write_to_png
#define cairo_set_target_ps		cairo_set_target_ps_DEPRECATED_BY_cairo_ps_surface_create
#define cairo_set_target_quartz		cairo_set_target_quartz_DEPRECATED_BY_cairo_quartz_surface_create
#define cairo_set_target_win32		cairo_set_target_win32_DEPRECATED_BY_cairo_win32_surface_create
#define cairo_set_target_xcb		cairo_set_target_xcb_DEPRECATED_BY_cairo_xcb_surface_create
#define cairo_set_target_drawable	cairo_set_target_drawable_DEPRECATED_BY_cairo_xlib_surface_create
#define cairo_get_status_string		cairo_get_status_string_DEPRECATED_BY_cairo_status_AND_cairo_status_to_string
#define cairo_status_string		cairo_status_string_DEPRECATED_BY_cairo_status_AND_cairo_status_to_string

#endif /* CAIRO_DEPRECATED_H */
