<?php

/**
 * @file
 * Default theme implementation for entities.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) entity label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-{ENTITY_TYPE}
 *   - {ENTITY_TYPE}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>


<style>
.left-table-col {
  background-color: #757575;
  color: white;
  font-weight: bold;
}

.column {
  float: left;
}

.col-left {
  width: 15%;
  padding-right: 10px;
}

.col-right {
  width: 80%;
}

ul.gene-nav-menu li {
  list-style-type: none;
}
</style>


<script type="text/javascript">
(function ($) {
 $(document).ready(function() {

  $('#col-expression').hide();
  $('#col-sequences').hide();

  $('ul.gene-nav-menu li').click(function(e){
      panel_to_show = "#col-" + $(this).find("span.t").text().toLowerCase();
      $('.panel').hide();  // hide all the elements of class panel
      $(panel_to_show).show();  // show whichever panel has been clicked
  });

  $('.mRNA').click(function(e) {
    $('.panel').hide();  // hide all the elements of class panel
    $('#col-sequences').show(); // show the sequences panel
  });
 });
})(jQuery);

</script>


<h1> TripalEntity--bio-data-6.tpl.php </h1>

<?php // dpm($TripalEntity, "via template"); ?>

<div class="row">

<div class="column col-left">
  <!-- vertical menu bar -->
  <ul class="gene-nav-menu">
    <li id="description"> <a href="#"><span class="t">Description</span></a> </li>
    <li id="sequences"> <a href="#"><span class="t">Sequences</span></a> </li>
    <?php if ($content['local__gene_expression'][0]['#markup']) { ?>
            <li id="expression">
              <a href="#"><span class="t">Expression</span></a> 
            </li>
    <?php } ?>
  </ul>
</div>


<div class="column col-right">

<div id="col-description" class="panel">
  <h2> Description </h2>

<table>
<tr>
  <td width="20%" class="left-table-col"> Gene Model Name </td>
  <td> <?php print render($content['schema__name'][0]['#markup']); ?> </td>
</tr>

<tr>
  <td class="left-table-col"> Micro Synteny View</td>
  <td>
    <?php print render($content['fields_extra_micro_synteny_view'][0]['#markup']); ?>
  </td>
</tr>

<tr>
  <td class="left-table-col"> Organism </td>
  <td>
    <?php print render($content['obi__organism'][0]['#markup']); ?>
  </td>
</tr>

<tr>
  <td class="left-table-col"> Assembly Version </td>
  <td>
    <?php  print render($content['local__gene_assembly_version'][0]['#markup']); ?>
  </td>
</tr>

<tr class="even">
  <td class="left-table-col"> Gene Model Build </td>
  <td>
    <?php print render($content['local__gene_model_build'][0]['#markup']); ?>
  </td>
</tr>

<tr>
  <td class="left-table-col"> Gene Family </td>
  <td>
    <?php print render($content['local__gene_family'][0]['#markup']); ?>
  </td>
</tr>

<tr class="even">
  <td valign="top" class="left-table-col"> Description </td>
  <td> <?php print render($content['local__gene_description'][0]['#markup']); ?>
  </td>
</tr>

<tr>
  <td class="left-table-col"> Protein Domains </td>
  <td>
    <?php print render($content['local__gene_protein_domains'][0]['#markup']); ?>
  </td>
</tr>

<tr class="even">
  <td class="left-table-col"> mRNA and protein identifiers
  (also see Sequences tab) </td>
  <td>
    <?php print render($content['fields_extra_mrna_protein_identifiers'][0]['#markup']); ?>
  </td>
</tr>
</table>
</div> <!-- ./col-description -->

<div id="col-sequences" class="panel">
<a name="sequences-top"></a>
<h2> Sequences </h2>
  <?php print render($content['local__gene_sequences'][0]['#markup']); ?>
</div> <!-- ./col-sequences -->


<div id="col-expression" class="panel">
<h2> Expression </h2>
  <?php print render($content['local__gene_expression'][0]['#markup']); ?>
</div> <!-- ./col-expression -->

</div> <!-- ./col-right -->

</div> <!-- ./row -->

