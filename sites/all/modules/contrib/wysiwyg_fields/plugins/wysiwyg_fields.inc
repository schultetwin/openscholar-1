<?php
/**
 * @file
 * Wysiwyg module plugin.
 */

/**
 * Implements hook_INCLUDE_plugin().
 */
function wysiwyg_fields_wysiwyg_fields_plugin() {
  $plugins = array();

  /**
   * $_SESSION['wysiwyg_fields'] contains active content type as
   * hook_wysiwyg_fields_plugin() provides no context.
   *
   * @see wysiwyg_fields_after_build()
   * @see wysiwyg_wysiwyg_fields_init()
   */
  if (isset($_SESSION['wysiwyg_fields'])) {
    foreach (content_fields() as $field) {
      if (!is_null(content_fields($field['field_name'], $_SESSION['wysiwyg_fields'])) && isset($field['widget']['wysiwyg_fields_status']) && $field['widget']['wysiwyg_fields_status']) {
        // Define Wysiwyg plugin.
        // @TODO - Wysiwyg plugins aren't being ordered by weight, fix.
        $plugins["wysiwyg_fields_{$field['field_name']}"] = array(
          'title' => $field['widget']['label'],
          'vendor url' => 'http://drupal.org/project/wysiwyg_fields',
          'icon file' => $field['widget']['wysiwyg_fields_icon'],
          'icon title' => $field['widget']['label'],
          'css path' => drupal_get_path('module', 'wysiwyg_fields') . '/plugins',
          'css file' => 'wysiwyg_fields.css',
          'settings' => array(),
        );

        // Enable Wysiwyg plugin.
        // @TODO - Provide fine grain control on Wysiwyg profile settings.
        foreach (wysiwyg_profile_load_all() as $profile) {
          $profile->settings = is_array($profile->settings) ? $profile->settings : array();
          $profile->settings['buttons'] = is_array($profile->settings['buttons']) ? $profile->settings['buttons'] : array();

          $id = "wysiwyg_fields_{$field['field_name']}";
          if (!isset($profile->settings['buttons']['drupal'][$id]) || empty($profile->settings['buttons']['drupal'][$id])) {
            $profile->settings['buttons']['drupal'][$id] = 1;
            db_query("UPDATE {wysiwyg} SET settings = '%s' WHERE format = %d", serialize($profile->settings), $profile->format);
          }
        }

        // Prevent dynamic JavaScript files from being parsed through locale.
        $parsed = variable_get('javascript_parsed', array());
        $js = drupal_get_path('module', 'wysiwyg_fields') . "/plugins/wysiwyg_fields_{$field['field_name']}/wysiwyg_fields_{$field['field_name']}.js";
        if (!in_array($js, $parsed)) {
          $parsed[] = $js;
        }
        variable_set('javascript_parsed', $parsed);
      }
    }
    unset($_SESSION['wysiwyg_fields']);
  }

  return $plugins;
}
