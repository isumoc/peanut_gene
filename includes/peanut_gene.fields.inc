<?php
/**
 * @file
 * Contains all field specific code outside the classes.
 */

/**
 * Implements hook_bundle_fields_info().
 *
 * This hook tells Drupal/Tripal about your new field type. Make sure you've created the
 * field (handles basic storage of your data), widget (provides user UI to set data),
 * and formatter (describes display of data on Entity Page) classes. These should be
 * located in the following directory: [your module]/includes/TripalFields/[classname].inc
 * with one file per class. Your field name should be [cv name]__[cvterm name] and the
 * classes should be named [field name], [field_name]_widget, [field name]_formatter
 * for the field, widget and formatter respectively. MAKE SURE YOU'VE CLEARED THE CACHE
 * SINCE ADDING THESE FILES so Tripal magic can find them or the following will fail.
 *
 * @param $entity_type
 *   This should be 'TripalEntity' for all Tripal Content.
 * @param $bundle
 *   This object describes the Type of Tripal Entity (e.g. Organism or Gene) this hook is
 *   being called for. However, since this hook creates field types (by definition not
 *   tied to a specific Tripal Content Type (bundle)) and since a field type will only be
 *   created if it doesn't already exist, this parameter doesn't actually matter.
 *   NOTE: If you do need to determine the bundle in this hook, we suggest inspecting
 *   the data_table since the label can be changed by site administrators.
 *
 * @return
 *   An array of field definitions. Each field in this array will be created if it
 *   doesn't already exist. To trigger create of fields when developing call
 *   tripal_refresh_bundle_fields() for the specific bundle.
 */
function peanut_gene_bundle_fields_info($entity_type, $bundle) {
  $fields = array();

  // Because we are expecting data housed in Chado we can use the 'data_table'
  // property of the bundle to determine if this bundle is really the one
  // we want the field to be associated with.
  if (isset($bundle->data_table) AND ($bundle->data_table == 'feature')) {
  /*
  *
  *  1. Begin GENE ASSEMBLY VERSION
  */
  // First add my term.
    tripal_insert_cvterm(array(
      'id' => 'local:gene_assembly_version',
      'name' => 'gene_assembly_version',
      'cv_name' => 'local',
      'definition' => 'Gene Assembly Version Desc.',
    ));

    // Then describe the field defined by that term.
    $field_name = 'local__gene_assembly_version';
    $field_type = 'local__gene_assembly_version';
    $fields[$field_name] = array(
      'field_name' => $field_name,
      'type' => $field_type,
      'cardinality' => 1,
      'locked' => FALSE,
      'storage' => array(
      'type' => 'tripal_no_storage',
      ),
    );

  /*
  *
  *  2. Begin GENE MODEL BUILD
  */
  // First add my term.
    tripal_insert_cvterm(array(
      'id' => 'local:gene_model_build',
      'name' => 'gene_model_build',
      'cv_name' => 'local',
      'definition' => 'Gene Model Build Desc.',
    ));

    // Then describe the field defined by that term.
    // TODO: change field_name to same value as field_type
    // $field_name = 'field_gene_model_build';
    //$field_type = 'gene_model_build';
    $field_name = 'local__gene_model_build';
    $field_type = 'local__gene_model_build';
    $fields[$field_name] = array(
      'field_name' => $field_name,
      'type' => $field_type,
      'cardinality' => 1,
      'locked' => FALSE,
      'storage' => array(
      'type' => 'tripal_no_storage',
      ),
    );

  /*
  *
  *  3. Begin GENE PROTEIN DOMAINS
  */
  // First add my term.
    tripal_insert_cvterm(array(
      'id' => 'local:gene_protein_domains',
      'name' => 'gene_protein_domains',
      'cv_name' => 'local',
      'definition' => 'Gene Protein Domains Desc.',
    ));

    // Then describe the field defined by that term.
    $field_name = 'local__gene_protein_domains';
    $field_type = 'local__gene_protein_domains';
    $fields[$field_name] = array(
      'field_name' => $field_name,
      'type' => $field_type,
      'cardinality' => 1,
      'locked' => FALSE,
      'storage' => array(
      'type' => 'tripal_no_storage',
      ),
    );


  /*
  *
  *  4. Begin GENE EXPRESSION
  */
  // First add my term.
    tripal_insert_cvterm(array(
      'id' => 'local:gene_expression',
      'name' => 'gene_expression',
      'cv_name' => 'local',
      'definition' => 'Gene Expression Desc.',
    ));

    // Then describe the field defined by that term.
    $field_name = 'local__gene_expression';
    $field_type = 'local__gene_expression';
    $fields[$field_name] = array(
      'field_name' => $field_name,
      'type' => $field_type,
      'cardinality' => 1,
      'locked' => FALSE,
      'storage' => array(
      'type' => 'tripal_no_storage',
      ),
    );


  /*
  *
  *  5. Begin GENE SEQUENCES
  */
  // First add my term.
    tripal_insert_cvterm(array(
      'id' => 'local:gene_sequences',
      'name' => 'gene_sequences',
      'cv_name' => 'local',
      'definition' => 'Gene Sequences Desc.',
    ));

    // Then describe the field defined by that term.
    $field_name = 'local__gene_sequences';
    $field_type = 'local__gene_sequences';
    $fields[$field_name] = array(
      'field_name' => $field_name,
      'type' => $field_type,
      'cardinality' => 1,
      'locked' => FALSE,
      'storage' => array(
      'type' => 'tripal_no_storage',
      ),
    );



  /*
  *
  *  6. Begin GENE START
  */
  // First add my term.
    tripal_insert_cvterm(array(
      'id' => 'local:gene_start',
      'name' => 'gene_start',
      'cv_name' => 'local',
      'definition' => 'Gene Start Desc.',
    ));

    // Then describe the field defined by that term.
    $field_name = 'local__gene_start';
    $field_type = 'local__gene_start';
    $fields[$field_name] = array(
      'field_name' => $field_name,
      'type' => $field_type,
      'cardinality' => 1,
      'locked' => FALSE,
      'storage' => array(
      'type' => 'tripal_no_storage',
      ),
    );

  /*
  *
  *  7. Begin GENE END
  */
  // First add my term.
    tripal_insert_cvterm(array(
      'id' => 'local:gene_end',
      'name' => 'gene_end',
      'cv_name' => 'local',
      'definition' => 'Gene End Desc.',
    ));

    // Then describe the field defined by that term.
    $field_name = 'local__gene_end';
    $field_type = 'local__gene_end';
    $fields[$field_name] = array(
      'field_name' => $field_name,
      'type' => $field_type,
      'cardinality' => 1,
      'locked' => FALSE,
      'storage' => array(
      'type' => 'tripal_no_storage',
      ),
    );


  /*
  *
  *  8. Begin GENE Species
  */
  // First add my term.
    tripal_insert_cvterm(array(
      'id' => 'local:gene_species',
      'name' => 'gene_species',
      'cv_name' => 'local',
      'definition' => 'Gene Species Desc.',
    ));

    // Then describe the field defined by that term.
    $field_name = 'local__gene_species';
    $field_type = 'local__gene_species';
    $fields[$field_name] = array(
      'field_name' => $field_name,
      'type' => $field_type,
      'cardinality' => 1,
      'locked' => FALSE,
      'storage' => array(
      'type' => 'tripal_no_storage',
      ),
    );

 /*
  *
  *  9. Begin GENE Chromosome
  */
  // First add my term.
    tripal_insert_cvterm(array(
      'id' => 'local:gene_chromosome',
      'name' => 'gene_chromosome',
      'cv_name' => 'local',
      'definition' => 'Gene Chromosome Desc.',
    ));

    // Then describe the field defined by that term.
    $field_name = 'local__gene_chromosome';
    $field_type = 'local__gene_chromosome';
    $fields[$field_name] = array(
      'field_name' => $field_name,
      'type' => $field_type,
      'cardinality' => 1,
      'locked' => FALSE,
      'storage' => array(
      'type' => 'tripal_no_storage',
      ),
    );

 /*
  *
  *  10. Begin GENE Name
  */
  // First add my term.
    tripal_insert_cvterm(array(
      'id' => 'local:gene_name',
      'name' => 'gene_name',
      'cv_name' => 'local',
      'definition' => 'Gene Name Desc.',
    ));

    // Then describe the field defined by that term.
    $field_name = 'local__gene_name';
    $field_type = 'local__gene_name';
    $fields[$field_name] = array(
      'field_name' => $field_name,
      'type' => $field_type,
      'cardinality' => 1,
      'locked' => FALSE,
      'storage' => array(
      'type' => 'tripal_no_storage',
      ),
    );


  /*
  *
  *  11. Begin GENE Description
  */
  // First add my term.
    tripal_insert_cvterm(array(
      'id' => 'local:gene_description',
      'name' => 'gene_description',
      'cv_name' => 'local',
      'definition' => 'Gene Description Desc.',
    ));

    // Then describe the field defined by that term.
    $field_name = 'local__gene_description';
    $field_type = 'local__gene_description';
    $fields[$field_name] = array(
      'field_name' => $field_name,
      'type' => $field_type,
      'cardinality' => 1,
      'locked' => FALSE,
      'storage' => array(
      'type' => 'tripal_no_storage',
      ),
    );


  /*
  *
  *  12. Begin GENE Description
  */
  // First add my term.
    tripal_insert_cvterm(array(
      'id' => 'local:gene_family',
      'name' => 'gene_family',
      'cv_name' => 'local',
      'definition' => 'Gene Family Desc.',
    ));

    // Then describe the field defined by that term.
    $field_name = 'local__gene_family';
    $field_type = 'local__gene_family';
    $fields[$field_name] = array(
      'field_name' => $field_name,
      'type' => $field_type,
      'cardinality' => 1,
      'locked' => FALSE,
      'storage' => array(
      'type' => 'tripal_no_storage',
      ),
    );



  } // end if isset()
  return $fields;
}

/**
 * Implements hook_bundle_instances_info().
 *
 * This hook tells Drupal/Tripal to create a field instance of a given field type on a
 * specific Tripal Content type (otherwise known as the bundle). Make sure to implement
 * hook_bundle_create_fields() to create your field type before trying to create an
 * instance of that field.
 *
 * @param $entity_type
 *   This should be 'TripalEntity' for all Tripal Content.
 * @param $bundle
 *   This object describes the Type of Tripal Entity (e.g. Organism or Gene) the field
 *   instances are being created for. Thus this hook is called once per Tripal Content Type on your
 *   site. The name of the bundle is the machine name of the type (e.g. bio_data_1) and
 *   the label of the bundle (e.g. Organism) is what you see in the interface. Since the
 *   label can be changed by site admin, we suggest checking the data_table to determine
 *   if this is the entity you want to add field instances to.
 * @return
 *   An array of field instance definitions. This is where you can define the defaults
 *   for any settings you use in your field. Each entry in this array will be used to
 *   create an instance of an already existing field.
 */
function peanut_gene_bundle_instances_info($entity_type, $bundle) {
  $instances = array();

  if (isset($bundle->data_table) AND ($bundle->data_table == 'feature')) {
    /*
    *
    *  1. Begin GENE ASSEMBLY VERSION
    */
    $field_name = 'local__gene_assembly_version';
    $field_type = 'local__gene_assembly_version';
    $instances[$field_name] =  array(
      'field_name' => $field_name,
      'entity_type' => $entity_type,
      'bundle' => $bundle->name,
      'label' => 'Gene Assembly Version',
      'description' => 'Gene Assembly Version Desc.',
      'required' => FALSE,
      'settings' => array(
      'auto_attach' => TRUE,
        // 'chado_table' => $bundle->data_table,
        // 'chado_column' => 'organism_id',
        // 'base_table' => $bundle->data_table,
      ),
      'widget' => array(
        'type' => 'local__gene_assembly_version_widget',
        'settings' => array(),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'local__gene_assembly_version_formatter',
          'settings' => array(),
        ),
      ),
    );

    /*
    *
    *  2. Begin GENE MODEL BUILD
    */
    $field_name = 'local__gene_model_build';
    $field_type = 'local__gene_model_build';
    $instances[$field_name] =  array(
      'field_name' => $field_name,
      'entity_type' => $entity_type,
      'bundle' => $bundle->name,
      'label' => 'Gene Model Build',
      'description' => 'Gene Model Build Desc.',
      'required' => FALSE,
      'settings' => array(
      'auto_attach' => TRUE,
        // 'chado_table' => $bundle->data_table,
        // 'chado_column' => 'organism_id',
        // 'base_table' => $bundle->data_table,
      ),
      'widget' => array(
        'type' => 'local__gene_model_build_widget',
        'settings' => array(),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'local__gene_model_build_formatter',
          'settings' => array(),
        ),
      ),
    );

    /*
    *
    *  3. Begin GENE PROTEIN DOMAINS
    */
    $field_name = 'local__gene_protein_domains';
    $field_type = 'local__gene_protein_domains';
    $instances[$field_name] =  array(
      'field_name' => $field_name,
      'entity_type' => $entity_type,
      'bundle' => $bundle->name,
      'label' => 'Gene Protein Domains',
      'description' => 'Gene Protein Domains Desc.',
      'required' => FALSE,
      'settings' => array(
      'auto_attach' => TRUE,
        // 'chado_table' => $bundle->data_table,
        // 'chado_column' => 'organism_id',
        // 'base_table' => $bundle->data_table,
      ),
      'widget' => array(
        'type' => 'local__gene_protein_domains_widget',
        'settings' => array(),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'local__gene_protein_domains_formatter',
          'settings' => array(),
        ),
      ),
    );

    /*
    *
    *  4. Begin GENE EXPRESSION
    */
    $field_name = 'local__gene_expression';
    $field_type = 'local__gene_expression';
    $instances[$field_name] =  array(
      'field_name' => $field_name,
      'entity_type' => $entity_type,
      'bundle' => $bundle->name,
      'label' => 'Gene Expression',
      'description' => 'Gene Expression Desc.',
      'required' => FALSE,
      'settings' => array(
      'auto_attach' => TRUE,
        // 'chado_table' => $bundle->data_table,
        // 'chado_column' => 'organism_id',
        // 'base_table' => $bundle->data_table,
      ),
      'widget' => array(
        'type' => 'local__gene_expression_widget',
        'settings' => array(),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'local__gene_expression_formatter',
          'settings' => array(),
        ),
      ),
    );

    /*
    *
    *  5. Begin GENE SEQUENCES
    */
    $field_name = 'local__gene_sequences';
    $field_type = 'local__gene_sequences';
    $instances[$field_name] =  array(
      'field_name' => $field_name,
      'entity_type' => $entity_type,
      'bundle' => $bundle->name,
      'label' => 'Gene Sequences',
      'description' => 'Gene Sequences Desc.',
      'required' => FALSE,
      'settings' => array(
      'auto_attach' => FALSE,
        // 'chado_table' => $bundle->data_table,
        // 'chado_column' => 'organism_id',
        // 'base_table' => $bundle->data_table,
      ),
      'widget' => array(
        'type' => 'local__gene_sequences_widget',
        'settings' => array(),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'local__gene_sequences_formatter',
          'settings' => array(),
        ),
      ),
    );


    /*
    *
    *  6. Begin GENE START
    */
    $field_name = 'local__gene_start';
    $field_type = 'local__gene_start';
    $instances[$field_name] =  array(
      'field_name' => $field_name,
      'entity_type' => $entity_type,
      'bundle' => $bundle->name,
      'label' => 'Gene Start',
      'description' => 'Gene Start Desc.',
      'required' => FALSE,
      'settings' => array(
      'auto_attach' => FALSE,
        // 'chado_table' => $bundle->data_table,
        // 'chado_column' => 'organism_id',
        // 'base_table' => $bundle->data_table,
      ),
      'widget' => array(
        'type' => 'local__gene_start_widget',
        'settings' => array(),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'local__gene_start_formatter',
          'settings' => array(),
        ),
      ),
    );


    /*
    *
    *  7. Begin GENE END
    */
    $field_name = 'local__gene_end';
    $field_type = 'local__gene_end';
    $instances[$field_name] =  array(
      'field_name' => $field_name,
      'entity_type' => $entity_type,
      'bundle' => $bundle->name,
      'label' => 'Gene End',
      'description' => 'Gene End Desc.',
      'required' => FALSE,
      'settings' => array(
      'auto_attach' => FALSE,
        // 'chado_table' => $bundle->data_table,
        // 'chado_column' => 'organism_id',
        // 'base_table' => $bundle->data_table,
      ),
      'widget' => array(
        'type' => 'local__gene_end_widget',
        'settings' => array(),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'local__gene_end_formatter',
          'settings' => array(),
        ),
      ),
    );


    /*
    *
    *  8. Begin GENE Species
    */
    $field_name = 'local__gene_species';
    $field_type = 'local__gene_species';
    $instances[$field_name] =  array(
      'field_name' => $field_name,
      'entity_type' => $entity_type,
      'bundle' => $bundle->name,
      'label' => 'Gene Species',
      'description' => 'Gene Species Desc.',
      'required' => FALSE,
      'settings' => array(
      'auto_attach' => FALSE,
        // 'chado_table' => $bundle->data_table,
        // 'chado_column' => 'organism_id',
        // 'base_table' => $bundle->data_table,
      ),
      'widget' => array(
        'type' => 'local__gene_species_widget',
        'settings' => array(),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'local__gene_species_formatter',
          'settings' => array(),
        ),
      ),
    );


    /*
    *
    *  9. Begin GENE Chromosome
    */
    $field_name = 'local__gene_chromosome';
    $field_type = 'local__gene_chromosome';
    $instances[$field_name] =  array(
      'field_name' => $field_name,
      'entity_type' => $entity_type,
      'bundle' => $bundle->name,
      'label' => 'Gene Chromosome',
      'description' => 'Gene Chromosome Desc.',
      'required' => FALSE,
      'settings' => array(
      'auto_attach' => FALSE,
        // 'chado_table' => $bundle->data_table,
        // 'chado_column' => 'organism_id',
        // 'base_table' => $bundle->data_table,
      ),
      'widget' => array(
        'type' => 'local__gene_chromosome_widget',
        'settings' => array(),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'local__gene_chromosome_formatter',
          'settings' => array(),
        ),
      ),
    );


    /*
    *
    *  10. Begin GENE Name
    */
    $field_name = 'local__gene_name';
    $field_type = 'local__gene_name';
    $instances[$field_name] =  array(
      'field_name' => $field_name,
      'entity_type' => $entity_type,
      'bundle' => $bundle->name,
      'label' => 'Gene Name',
      'description' => 'Gene Name Desc.',
      'required' => FALSE,
      'settings' => array(
      'auto_attach' => FALSE,
        // 'chado_table' => $bundle->data_table,
        // 'chado_column' => 'organism_id',
        // 'base_table' => $bundle->data_table,
      ),
      'widget' => array(
        'type' => 'local__gene_name_widget',
        'settings' => array(),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'local__gene_name_formatter',
          'settings' => array(),
        ),
      ),
    );


    /*
    *
    *  11. Begin GENE Description
    */
    $field_name = 'local__gene_description';
    $field_type = 'local__gene_description';
    $instances[$field_name] =  array(
      'field_name' => $field_name,
      'entity_type' => $entity_type,
      'bundle' => $bundle->name,
      'label' => 'Gene Description',
      'description' => 'Gene Description Desc.',
      'required' => FALSE,
      'settings' => array(
      'auto_attach' => FALSE,
        // 'chado_table' => $bundle->data_table,
        // 'chado_column' => 'organism_id',
        // 'base_table' => $bundle->data_table,
      ),
      'widget' => array(
        'type' => 'local__gene_description_widget',
        'settings' => array(),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'local__gene_description_formatter',
          'settings' => array(),
        ),
      ),
    );


    /*
    *
    *  12. Begin GENE Family
    */
    $field_name = 'local__gene_family';
    $field_type = 'local__gene_family';
    $instances[$field_name] =  array(
      'field_name' => $field_name,
      'entity_type' => $entity_type,
      'bundle' => $bundle->name,
      'label' => 'Gene Family',
      'description' => 'Gene Family Desc.',
      'required' => FALSE,
      'settings' => array(
      'auto_attach' => FALSE,
        // 'chado_table' => $bundle->data_table,
        // 'chado_column' => 'organism_id',
        // 'base_table' => $bundle->data_table,
      ),
      'widget' => array(
        'type' => 'local__gene_family_widget',
        'settings' => array(),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'local__gene_family_formatter',
          'settings' => array(),
        ),
      ),
    );


  }  //end if isset()
  return $instances;
}
