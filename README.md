This module generates a graph of the entities, fields and their relationships of
a particular installation of Drupal 7. This enables a quick overview of your
Drupal 7 entities and bundles.

This is an altered version (fork) of the original entitiesdiagram module
(https://github.com/Gizra/entitiesdiagram) that provides some hooks and supports
rendering using the PlantUML library.

The PlantUML output format groups entity types together and shows entity type /
entity bundle relations in a psuedo-UML parent-child inheritance style. Since
Drupal 7 entity bundles have no real OOP class inheritance, this is very
experimental and only meant to provide a simple overview of bundles and fields.
The result uses UML items to visualize this, but is not a proper UML diagram.

Color swatches can be manipulated via hook_entityrelationships_entitygraph_color_swatches()
and the graph itself can be modified via entityrelationships_entitygraph().


# Usage Drush

    $ drush entityrelations | dot -Gratio=0.7 -Eminlen=2 -T png -o ./test.png

    $ drush entityrelations --include_fields --entity_type=node | dot -Gratio=0.7 -Eminlen=2 -T png -o ./test.png

    $ drush entityrelations --include_fields | java -jar /path/to/plantuml.jar -pipe > ./test.png

    $ drush entityrelations --include_fields | java -jar /path/to/plantuml.jar -pipe -tsvg > ./test.svg
