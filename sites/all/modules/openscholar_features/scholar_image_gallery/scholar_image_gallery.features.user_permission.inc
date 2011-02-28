<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_image_gallery_user_default_permissions() {
  $permissions = array();

  // Exported permission: create gallery content
  $permissions['create gallery content'] = array(
    'name' => 'create gallery content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: create image content
  $permissions['create image content'] = array(
    'name' => 'create image content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: delete own gallery content
  $permissions['delete own gallery content'] = array(
    'name' => 'delete own gallery content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: delete own image content
  $permissions['delete own image content'] = array(
    'name' => 'delete own image content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: edit own gallery content
  $permissions['edit own gallery content'] = array(
    'name' => 'edit own gallery content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: edit own image content
  $permissions['edit own image content'] = array(
    'name' => 'edit own image content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override gallery promote to front page option
  $permissions['override gallery promote to front page option'] = array(
    'name' => 'override gallery promote to front page option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override gallery sticky option
  $permissions['override gallery sticky option'] = array(
    'name' => 'override gallery sticky option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  return $permissions;
}