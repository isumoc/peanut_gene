<?php
/**
 * @class
 * Purpose:
 *
 * Display:
 * Configuration:
 */
class local__gene_sequences_formatter extends TripalFieldFormatter {

  // The default label for this field.
  public static $default_label = 'Gene Sequences';

  // The list of field types for which this formatter is appropriate.
  public static $field_types = array('local__gene_sequences');

  // The list of default settings for this formatter.
  public static $default_settings = array(
    'key' => 'default_value',
  );

  /**
   * Provides the field's setting form.
   *
   * This function corresponds to the hook_field_formatter_settings_form()
   * function of the Drupal Field API.
   *
   * The settings form appears on the 'Manage Display' page of the content
   * type administration page. This function provides the form that will
   * appear on that page.
   *
   * To add a validate function, please create a static function in the
   * implementing class, and indicate that this function should be used
   * in the form array that is returned by this function.
   *
   * This form will not be displayed if the formatter_settings_summary()
   * function does not return anything.
   *
   * param $field
   *   The field structure being configured.
   * param $instance
   *   The instance structure being configured.
   * param $view_mode
   *   The view mode being configured.
   * param $form
   *   The (entire) configuration form array, which will usually have no use
   *   here.  Typically for reference only.
   * param $form_state
   *   The form state of the (entire) configuration form.
   *
   * @return
   *   A Drupal Form array containing the settings form for this field.
   */
  public function settingsForm($view_mode, $form, &$form_state) {
  }

  /**
   *  Provides the display for a field
   *
   * This function corresponds to the hook_field_formatter_view()
   * function of the Drupal Field API.
   *
   *  This function provides the display for a field when it is viewed on
   *  the web page.  The content returned by the formatter should only include
   *  what is present in the $items[$delta]['values] array. This way, the
   *  contents that are displayed on the page, via webservices and downloaded
   *  into a CSV file will always be identical.  The view need not show all
   *  of the data in the 'values' array.
   *
   *  @param $element
   *  @param $entity_type
   *  @param $entity
   *  @param $langcode
   *  @param $items
   *  @param $display
   *
   *  @return
   *    An element array compatible with that returned by the
   *    hook_field_formatter_view() function.
   */
  public function view(&$element, $entity_type, $entity, $langcode, $items, $display) {

    // Get the settings
    $settings = $display['settings'];

    $mRNAs = $items[0]['value']['SO:sequence_of'];
    $gene_model_name = $items[0]['value']['schema:name'];

    // number of bases per line in FASTA format
    $num_bases = 50;

    ///////////////////////   PREPARE THE RECORD TABLE   ////////////////////////

    // the $headers array is an array of fields to use as the column headers.
    // additional documentation can be found here
    // https://api.drupal.org/api/drupal/includes%21theme.inc/function/theme_table/7
    // This table for the analysis has a vertical header (down the first column)
    // so we do not provide headers here, but specify them in the $rows array below.
    $headers = array();

    // the $rows array contains an array of rows where each row is an array
    // of values for each column of the table in that row.  Additional documentation
    // can be found here:
    // https://api.drupal.org/api/drupal/includes%21theme.inc/function/theme_table/7
    $rows = array();

    // Name row
    $rows[] = array(
      array(
        'data' => 'Gene Model Name',
        'header' => TRUE,
        'width' => '20%',
      ),
      $gene_model_name
    );

    // Name row
    $rows[] = array(
      array(
        'data' => '',
        'header' => TRUE,
        'width' => '20%',
      ),
      'This gene model has ' . count($mRNAs) . ' associated mRNAs',
    );

    /////// SEPARATOR /////////
    $rows[] = array(
      array(
        'data' => '',
        'header' => TRUE,
        'height' => 6,
        'style' => 'background-color:white',
      ),
      array(
        'data' => '',
        'style' => 'background-color:white',
      ),
    );

    $sequence_display_name = $mRNAs['local:gene_mrna']['local:gene_pep_name'];

    foreach (array_keys($mRNAs) as $mRNA_name) {
      $wrapped = wordwrap($mRNAs[$mRNA_name]['local:gene_residues'], $num_bases, "<br>", TRUE);
      $seq_html = <<<SEQ
        <div id="residues" class="tripal_feature-sequence-item">
        <p><b>$sequence_display_name sequence</b></p>
        <pre class="tripal_feature-sequence">>$sequence_display_name\n$wrapped</pre>
        <a href="#sequences-top">back to top</a>
        </div>
SEQ;
      $rows[] = array(
        array(
          'data' => 'mRNA Sequence',
          'header' => TRUE,
          'width' => '20%',
        ),
        "<a name='$mRNA_name'></a>$seq_html"
      );

      // polypetide sequence
      $wrapped = wordwrap($mRNAs[$mRNA_name]['local:gene_pep_residues'], $num_bases, "<br>", TRUE);
      $seq_html = <<<SEQ
        <div id="residues" class="tripal_feature-sequence-item">
        <p><b>$sequence_display_name sequence</b></p>
        <pre class="tripal_feature-sequence">>$sequence_display_name\n$wrapped</pre>
        <a href="#sequences-top">back to top</a>
        </div>
SEQ;
      $rows[] = array(
        array(
          'data' => 'Protein Sequence',
          'header' => TRUE,
          'width' => '20%',
        ),
        $seq_html
      );

      /////// SEPARATOR /////////
      $rows[] = array(
        array(
          'data' => '',
          'header' => TRUE,
          'height' => 6,
          'style' => 'background-color:white',
        ),
        array(
          'data' => '',
          'style' => 'background-color:white',
        ),
      );
    }// end foreach mRNA

    // the $table array contains the headers and rows array as well as other
    // options for controlling the display of the table.  Additional
    // documentation can be found here:
    // https://api.drupal.org/api/drupal/includes%21theme.inc/function/theme_table/7
    $table = array(
      'header' => $headers,
      'rows' => $rows,
      'attributes' => array(
        'id' => 'tripal_feature-table-base',
        'class' => 'tripal-data-table'
      ),
      'sticky' => FALSE,
      'caption' => '',
      'colgroups' => array(),
      'empty' => '',
    );

    // once we have our table array structure defined, we call Drupal's theme_table()
    // function to generate the table.
    $sequence_content = theme_table($table);

    $element = array(
      array( '#markup' => $sequence_content ),
    );

    return $element;

  }

  /**
   * Provides a summary of the formatter settings.
   *
   * This function corresponds to the hook_field_formatter_settings_summary()
   * function of the Drupal Field API.
   *
   * On the 'Manage Display' page of the content type administration page,
   * fields are allowed to provide a settings form.  This settings form can
   * be used to allow the site admin to define how the field should be
   * formatted.  The settings are then available for the formatter()
   * function of this class.  This function provides a text-based description
   * of the settings for the site developer to see.  It appears on the manage
   * display page inline with the field.  A field must always return a
   * value in this function if the settings form gear button is to appear.
   *
   * See the hook_field_formatter_settings_summary() function for more
   * information.
   *
   * @param $field
   * @param $instance
   * @param $view_mode
   *
   * @return string
   *   A string that provides a very brief summary of the field settings
   *   to the user.
   *
   */
  public function settingsSummary($view_mode) {
  }

}
