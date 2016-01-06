<?php

/**
 * Lab 03, Exercise 2 — Person class
 * @author Haroen Viaene <hello@haroen.me>
 */

	class Person {
		static $familySize = 0;
		private $name;
		private $parents;
		private $children;

		public function __construct($name,$parent1=null,$parent2=null) {
			$this->name = $name;
			$this->children = [];
			if ($parent1 !== null && $parent2 !== null) {
				$this->parents = [$parent1,$parent2];
				$parent1->children[] = $this;
				$parent2->children[] = $this;
			}
			$this::$familySize++;
		}

		public function __toString()
		{
			return $this->name;
		}

		public function getParents() {
			return $this->parents;
		}

		public function getChildren() {
			return $this->children;
		}

		public function getSiblings() {
			$siblings = array_intersect($this->parents[0]->getChildren(), $this->parents[1]->getChildren());
			if (($index = array_search($this, $siblings)) !== false) {
				unset($siblings[$index]);
			}
			return $siblings;
		}
	}

	$hub = new Person('Hubert');
	$gis = new Person('Gislaine');
	$gas = new Person('Gaston', $gis, $hub);
	$bla = new Person('Bla',$gas,$hub);
	$hey = new Person('Hey',$bla,$gas);
	$jor = new Person('Jorisje',$hey,$gas);
	$fer = new Person('Ferre',$hey,$gas);

	echo 'Opgave 2' . '<br/>' . PHP_EOL;

	echo $hub . '<br/>';
	echo $gas . '’s parents: ' . implode(' + ', $gas->getParents()) . '<br/>' . PHP_EOL;
	echo $bla . '’s parents: ' . implode(' + ', $bla->getParents()) . '<br/>' . PHP_EOL;
	echo $fer . '‘s siblings: ' . implode(' + ', $fer->getSiblings()) . '<br/>' . PHP_EOL;
	echo Person::$familySize;

// EOF