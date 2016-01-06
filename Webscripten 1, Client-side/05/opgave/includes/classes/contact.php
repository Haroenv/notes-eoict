<?php

	/**
	* Contact entity class
	*
	* @author    Rogier van der Linde <rogier.vanderlinde@kahosl.be>
	*/

	class Contact {

		/**
		* public members 
		*/
		public $id;
		public $name;
		public $email;
		public $role;
		public $comments;
		public $sortorder;

		/**
		* Class constructor.
		*
		* @param id[optional] 
		* @param name[optional] 
		* @param email[optional] 
		* @param role[optional] 
		* @param comments[optional] 
		* @param sortorder[optional] 
		*/
		function __construct($id = -1, $name = '', $email = '', $role = '', $comments = '', $sortorder = -1) {
			$this->id = (int) $id;
			$this->name = $name;
			$this->email = $email;
			$this->role = $role;
			$this->comments = $comments;
			$this->sortorder = (int) $sortorder;
		}

	}

// EOF
