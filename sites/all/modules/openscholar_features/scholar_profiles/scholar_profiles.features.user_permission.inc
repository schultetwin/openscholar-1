<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_profiles_user_default_permissions() {
  $permissions = array();

  // Exported permission: create person content
  $permissions['create person content'] = array(
    'name' => 'create person content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: delete own person content
  $permissions['delete own person content'] = array(
    'name' => 'delete own person content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: edit own person content
  $permissions['edit own person content'] = array(
    'name' => 'edit own person content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override person promote to front page option
  $permissions['override person promote to front page option'] = array(
    'name' => 'override person promote to front page option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override person published option
  $permissions['override person published option'] = array(
    'name' => 'override person published option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override person sticky option
  $permissions['override person sticky option'] = array(
    'name' => 'override person sticky option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  return $permissions;
}