<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function vsite_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => 1);
  }
  elseif ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_flag_default_flags().
 */
function vsite_flag_default_flags() {
  $flags = array();
  // Exported flag: "Featured Posts".
  $flags['featuredposts'] = array(
    'content_type' => 'node',
    'title' => 'Featured Posts',
    'global' => '1',
    'types' => array(),
    'flag_short' => 'Feature this post',
    'flag_long' => 'Make this a featured post',
    'flag_message' => '',
    'unflag_short' => 'Un-feature this post',
    'unflag_long' => 'No longer feature this post',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        '0' => 2,
      ),
      'unflag' => array(
        '0' => 2,
      ),
    ),
    'show_on_page' => 0,
    'show_on_teaser' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'vsite',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function vsite_imagecache_default_presets() {
  $items = array(
    'square_35_35' => array(
      'presetname' => 'square_35_35',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '35',
            'height' => '35',
          ),
        ),
      ),
    ),
    'square_50_50' => array(
      'presetname' => 'square_50_50',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '50',
            'height' => '50',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function vsite_node_info() {
  $items = array(
    'vsite' => array(
      'name' => t('Scholar site'),
      'module' => 'features',
      'description' => t('Represent a Virtual Web Site'),
      'has_title' => '1',
      'title_label' => t('Site title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function vsite_views_api() {
  return array(
    'api' => '2',
  );
}
