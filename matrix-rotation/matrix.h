/**
 * Matrix class that defines a matrix.
 *
 * @author: Manuel Cruz
 * @version 1.0
 * @date June 3, 2020
 */
class Matrix {
	private:
		/** The elements of this Matrix */
		int** values;
		
		/** Number of rows of this matrix */
		int rows;
		
		/** Number of columns of this matrix */
		int columns;
		
		/** Allocate memory for this matrix */
		void allocateMemory();
		
		/** Deallocate memory for this matrix */
		void deallocateMemory();
		
	public:
		/**
		 * Explicit constructor of matrix.
		 *
		 * @param rows - number of rows of this matrix
		 * @param columns - number of columns of this matrix
		 */
		explicit Matrix(int rows, int columns);
		
		/**
		 * Destructor of matrix.
		 */
		~Matrix();
		
		/**
		 * Gets the value at the given row and column.
		 *
		 * @param row - row of matrix
		 * @param column - column of matrix
		 *
		 * @return value at the given row and column
		 */
		int get(int row, int column);
		
		/**
		 * Sets the value at the given row and column.
		 *
		 * @row - row of matrix
		 * @column - column of matrix
		 * @value - value to set
		 */
		void set(int row, int column, int value);
		
		/**
		 * Sets the values of this matrix. Assuming this array is
		 * the same size as this matrix.
		 *
		 * @param array - values to be set.
		 */
		void setValues(int** array);
		
		/**
		 * Gets the number of rows of this matrix.
		 *
		 * @return number of rows
		 */
		int getRows();
		
		/**
		 * Gets the number of columns of this matrix
		 *
		 * @return number of columns
		 */
		int getColumns();
		
		/**
		 * Rotates this matrix counter-clockwise.
		 *
		 * @param rotations - number of rotation to give to this matrix.
		 */
		void rotate(int rotations);
		
		/**
		 * Prints this matrix to the screen
		 */
		void print();
};
