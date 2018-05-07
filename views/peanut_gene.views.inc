<?php
/**
 * @file
 * Describe default gene views
 */

/**
 * Implements hook_views_default_views().
 *
 * @ingroup tripal_gene
 */
function peanut_gene_views_default_views() {

  $views = array();

  $view = peanut_gene_defaultvalue_user_genes();
  $view = tripal_make_view_compatible_with_external($view);
  $views[$view->name] = $view;

  return $views;
}

/**
 * Defines the gene user search default view.
 *
 * @ingroup tripal_gene
 */
function peanut_gene_defaultvalue_user_genes() {

  $view = new view();
  $view->name = 'search_api_gene_index';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_gene_search';
  $view->human_name = 'Search API Gene Index';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search API Gene Index';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view bio_data_6';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'local_gene_name' => 'local_gene_name',
    'local_gene_species' => 'local_gene_species',
    'local_gene_chromosome' => 'local_gene_chromosome',
    'local_gene_start' => 'local_gene_start',
    'local_gene_end' => 'local_gene_end',
    'local_gene_family' => 'local_gene_family',
    'local_gene_description' => 'local_gene_description',
    'local_gene_protein_domains' => 'local_gene_protein_domains',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'local_gene_name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'local_gene_species' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'local_gene_chromosome' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'local_gene_start' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'local_gene_end' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'local_gene_family' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'local_gene_description' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'local_gene_protein_domains' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = 'Displaying @start - @end of @total genes';
  /* Field: Indexed Tripal Content: Tripal content ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'search_api_index_gene_search';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'Entity ID';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  $handler->display->display_options['fields']['id']['link_to_entity'] = 0;
  /* Field: Indexed Tripal Content: Gene Name */
  $handler->display->display_options['fields']['local_gene_name']['id'] = 'local_gene_name';
  $handler->display->display_options['fields']['local_gene_name']['table'] = 'search_api_index_gene_search';
  $handler->display->display_options['fields']['local_gene_name']['field'] = 'local_gene_name';
  /* Field: Indexed Tripal Content: Gene Species */
  $handler->display->display_options['fields']['local_gene_species']['id'] = 'local_gene_species';
  $handler->display->display_options['fields']['local_gene_species']['table'] = 'search_api_index_gene_search';
  $handler->display->display_options['fields']['local_gene_species']['field'] = 'local_gene_species';
  $handler->display->display_options['fields']['local_gene_species']['label'] = 'Species';
  /* Field: Indexed Tripal Content: Gene Chromosome */
  $handler->display->display_options['fields']['local_gene_chromosome']['id'] = 'local_gene_chromosome';
  $handler->display->display_options['fields']['local_gene_chromosome']['table'] = 'search_api_index_gene_search';
  $handler->display->display_options['fields']['local_gene_chromosome']['field'] = 'local_gene_chromosome';
  $handler->display->display_options['fields']['local_gene_chromosome']['label'] = 'Chromosome';
  /* Field: Indexed Tripal Content: Gene Start */
  $handler->display->display_options['fields']['local_gene_start']['id'] = 'local_gene_start';
  $handler->display->display_options['fields']['local_gene_start']['table'] = 'search_api_index_gene_search';
  $handler->display->display_options['fields']['local_gene_start']['field'] = 'local_gene_start';
  $handler->display->display_options['fields']['local_gene_start']['label'] = 'START';
  /* Field: Indexed Tripal Content: Gene End */
  $handler->display->display_options['fields']['local_gene_end']['id'] = 'local_gene_end';
  $handler->display->display_options['fields']['local_gene_end']['table'] = 'search_api_index_gene_search';
  $handler->display->display_options['fields']['local_gene_end']['field'] = 'local_gene_end';
  $handler->display->display_options['fields']['local_gene_end']['label'] = 'END';
  /* Field: Indexed Tripal Content: Gene Family */
  $handler->display->display_options['fields']['local_gene_family']['id'] = 'local_gene_family';
  $handler->display->display_options['fields']['local_gene_family']['table'] = 'search_api_index_gene_search';
  $handler->display->display_options['fields']['local_gene_family']['field'] = 'local_gene_family';
  /* Field: Indexed Tripal Content: Gene Description */
  $handler->display->display_options['fields']['local_gene_description']['id'] = 'local_gene_description';
  $handler->display->display_options['fields']['local_gene_description']['table'] = 'search_api_index_gene_search';
  $handler->display->display_options['fields']['local_gene_description']['field'] = 'local_gene_description';
  $handler->display->display_options['fields']['local_gene_description']['label'] = 'Description';
  /* Field: Indexed Tripal Content: Gene Protein Domains */
  $handler->display->display_options['fields']['local_gene_protein_domains']['id'] = 'local_gene_protein_domains';
  $handler->display->display_options['fields']['local_gene_protein_domains']['table'] = 'search_api_index_gene_search';
  $handler->display->display_options['fields']['local_gene_protein_domains']['field'] = 'local_gene_protein_domains';
  $handler->display->display_options['fields']['local_gene_protein_domains']['label'] = 'Domains';
  /* Filter criterion: Indexed Tripal Content: Gene Species */
  $handler->display->display_options['filters']['local_gene_species']['id'] = 'local_gene_species';
  $handler->display->display_options['filters']['local_gene_species']['table'] = 'search_api_index_gene_search';
  $handler->display->display_options['filters']['local_gene_species']['field'] = 'local_gene_species';
  $handler->display->display_options['filters']['local_gene_species']['group'] = 1;
  $handler->display->display_options['filters']['local_gene_species']['exposed'] = TRUE;
  $handler->display->display_options['filters']['local_gene_species']['expose']['operator_id'] = 'local_gene_species_op';
  $handler->display->display_options['filters']['local_gene_species']['expose']['label'] = 'Species';
  $handler->display->display_options['filters']['local_gene_species']['expose']['operator'] = 'local_gene_species_op';
  $handler->display->display_options['filters']['local_gene_species']['expose']['identifier'] = 'local_gene_species';
  $handler->display->display_options['filters']['local_gene_species']['expose']['remember_roles'] = array(
    2 => '2',
    4 => 0,
    1 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Indexed Tripal Content: Gene Protein Domains */
  $handler->display->display_options['filters']['local_gene_protein_domains']['id'] = 'local_gene_protein_domains';
  $handler->display->display_options['filters']['local_gene_protein_domains']['table'] = 'search_api_index_gene_search';
  $handler->display->display_options['filters']['local_gene_protein_domains']['field'] = 'local_gene_protein_domains';
  $handler->display->display_options['filters']['local_gene_protein_domains']['group'] = 1;
  $handler->display->display_options['filters']['local_gene_protein_domains']['exposed'] = TRUE;
  $handler->display->display_options['filters']['local_gene_protein_domains']['expose']['operator_id'] = 'local_gene_protein_domains_op';
  $handler->display->display_options['filters']['local_gene_protein_domains']['expose']['label'] = 'Domains';
  $handler->display->display_options['filters']['local_gene_protein_domains']['expose']['description'] = '(e.g. [contains]: PF05659)';
  $handler->display->display_options['filters']['local_gene_protein_domains']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['local_gene_protein_domains']['expose']['operator'] = 'local_gene_protein_domains_op';
  $handler->display->display_options['filters']['local_gene_protein_domains']['expose']['identifier'] = 'local_gene_protein_domains';
  $handler->display->display_options['filters']['local_gene_protein_domains']['expose']['remember_roles'] = array(
    2 => '2',
    4 => 0,
    1 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Indexed Tripal Content: Gene Description */
  $handler->display->display_options['filters']['local_gene_description']['id'] = 'local_gene_description';
  $handler->display->display_options['filters']['local_gene_description']['table'] = 'search_api_index_gene_search';
  $handler->display->display_options['filters']['local_gene_description']['field'] = 'local_gene_description';
  $handler->display->display_options['filters']['local_gene_description']['group'] = 1;
  $handler->display->display_options['filters']['local_gene_description']['exposed'] = TRUE;
  $handler->display->display_options['filters']['local_gene_description']['expose']['operator_id'] = 'local_gene_description_op';
  $handler->display->display_options['filters']['local_gene_description']['expose']['label'] = 'Description';
  $handler->display->display_options['filters']['local_gene_description']['expose']['description'] = '(e.g. [Contains]: proteasome)';
  $handler->display->display_options['filters']['local_gene_description']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['local_gene_description']['expose']['operator'] = 'local_gene_description_op';
  $handler->display->display_options['filters']['local_gene_description']['expose']['identifier'] = 'local_gene_description';
  $handler->display->display_options['filters']['local_gene_description']['expose']['remember_roles'] = array(
    2 => '2',
    4 => 0,
    1 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Indexed Tripal Content: Gene Family */
  $handler->display->display_options['filters']['local_gene_family']['id'] = 'local_gene_family';
  $handler->display->display_options['filters']['local_gene_family']['table'] = 'search_api_index_gene_search';
  $handler->display->display_options['filters']['local_gene_family']['field'] = 'local_gene_family';
  $handler->display->display_options['filters']['local_gene_family']['group'] = 1;
  $handler->display->display_options['filters']['local_gene_family']['exposed'] = TRUE;
  $handler->display->display_options['filters']['local_gene_family']['expose']['operator_id'] = 'local_gene_family_op';
  $handler->display->display_options['filters']['local_gene_family']['expose']['label'] = 'Gene Family';
  $handler->display->display_options['filters']['local_gene_family']['expose']['description'] = '(e.g. [is equal to]: phytozome_10_2.59192412)';
  $handler->display->display_options['filters']['local_gene_family']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['local_gene_family']['expose']['operator'] = 'local_gene_family_op';
  $handler->display->display_options['filters']['local_gene_family']['expose']['identifier'] = 'local_gene_family';
  $handler->display->display_options['filters']['local_gene_family']['expose']['remember_roles'] = array(
    2 => '2',
    4 => 0,
    1 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Indexed Tripal Content: Gene Name */
  $handler->display->display_options['filters']['local_gene_name']['id'] = 'local_gene_name';
  $handler->display->display_options['filters']['local_gene_name']['table'] = 'search_api_index_gene_search';
  $handler->display->display_options['filters']['local_gene_name']['field'] = 'local_gene_name';
  $handler->display->display_options['filters']['local_gene_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['local_gene_name']['expose']['operator_id'] = 'local_gene_name_op';
  $handler->display->display_options['filters']['local_gene_name']['expose']['label'] = 'Gene Name';
  $handler->display->display_options['filters']['local_gene_name']['expose']['description'] = '(e.g. [Contains]: Aradu.010B0)';
  $handler->display->display_options['filters']['local_gene_name']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['local_gene_name']['expose']['operator'] = 'local_gene_name_op';
  $handler->display->display_options['filters']['local_gene_name']['expose']['identifier'] = 'local_gene_name';
  $handler->display->display_options['filters']['local_gene_name']['expose']['remember_roles'] = array(
    2 => '2',
    4 => 0,
    1 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'search-api-gene-index';

  return $view;
}

