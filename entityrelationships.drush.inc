<?php

/**
 * Implements hook_drush_command().
 */
function entityrelationships_drush_command() {
  $items['entityrelations'] = array(
    'description' => 'Generate a graph of the entities and fields.',
    'aliases' => array('ers'),
    'options' => array(
      'include_fields' => 'Include fields',
      'entity_type' => 'Select a single entity type',
      'render_engine' => 'Specify rendering engine: dot (default) or plantuml',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'core' => array('7+'),
    'drupal dependencies' => array('field'),
    'examples' => array(
      'drush entityrelations | dot -Gratio=0.7 -Eminlen=2 -T png -o ./test.png' => 'Generate the Entity-Relationship graph for the current site and export it as a PNG image.',
      'drush entityrelations --include_fields --entity_type=node | dot -Gratio=0.7 -Eminlen=2 -T png -o ./test.png' => 'Generate the Entity-Relationship graph for a entity type site including fields and export it as a PNG image.',
      'drush entityrelations --include_fields | java -jar /path/to/plantuml.jar -pipe > ./test.png' => 'Generate the Entity-Relationship graph including fields and export it as a PNG image using PlantUML.',
      'drush entityrelations --include_fields | java -jar /path/to/plantuml.jar -pipe -tsvg > ./test.svg' => 'Generate the Entity-Relationship graph including fields and export it in SVG format using PlantUML.',
    ),
  );
  return $items;
}

function drush_entityrelationships_entityrelations() {
  $include_fields = drush_get_option('include_fields', FALSE);
  $entity_type = drush_get_option('entity_type', FALSE);
  $render_engine = drush_get_option('render_engine', 'dot');
  $graph = entityrelationships_entitygraph($include_fields, $entity_type);
  echo entityrelationships_entitygraph_generate($graph, $render_engine);
}
