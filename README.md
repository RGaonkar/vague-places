vague-places
============
Vagueplaces Generator using DBpedia SPARQL endpoint.

Jordi Castells
10 August 2012

This software is implemented as a final project of a Geoinformatics Master course at ITC Faculty of Geo-Information Science and Earth Observation. With Dr. ir. R.A. (Rolf) de By supervisor.

The main course file is vagueplaces.py

Abstract
========
Online gazetteers provide services that help to geocode locations. Given the name, the gazetteerwill attempt to provide coordinates for the place, usually in point information. Point informationis not always the best solution: urban areas, administrative units, or rivers are better describedusing polygons or lines. There is a clear need for region geocoding.In ofﬁcial administrative units, the situation is not critical. This kind of data is most of thetime available from online spatial data repositories. On the other hand, non-ofﬁcial boundariesare difﬁcult to ﬁnd and, old boundaries or folklore delimitations difﬁcult to obtain. For example,Mittelland in Switzerland or the Scottish highlands.Solutions regarding the web are already proposed by Arampatzis et al. and Christopher B. Jones et al. inside the research by the SPIRIT project. Thoseapproaches use google search and classiﬁcation to obtain the information; this project will aim toobtain similar results using semantic web approaches.

Previous work presented a solution to the problem. The main aim of this small project is to provideanother way to obtain a similar or better solution with the aid of the semantic web formats using DBpediaas a base data repository

Requirements
============
To run vagueplaces.py you will have to provide a couple of libraries:
shapely
SPARQLWrapper

Official Report
===============
The official report can be found in PDF format either in Scribd or Mendeley:

http://www.scribd.com/doc/111990720/Defining-vague-places-with-web-knowledge
http://www.mendeley.com/profiles/jordi-castells/
