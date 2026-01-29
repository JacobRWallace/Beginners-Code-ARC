import React, { useState, useEffect } from 'react'; 
import axios from 'axios';
import ProductCard from '../components/ProductCard';
 
export default function Home() { 
  const [products, setProducts] = useState([]);
  const [searchTerm, setSearchTerm] = useState('');
  const [sortType, setSortType] = useState('');

  // Fetch products from backend
  useEffect(() => {
    axios.get('http://localhost:5000/api/products')
      .then(res => setProducts(res.data))
      .catch(err => console.error('Error fetching products:', err));
  }, []);

  const filteredProducts = products  
    .filter(p =>
      p.name.toLowerCase().includes(searchTerm.toLowerCase()) 
    ) 
    .sort((a, b) => {
      if (sortType === 'a-z') return a.name.localeCompare(b.name);
      if (sortType === 'z-a') return b.name.localeCompare(a.name);
      if (sortType === 'price-asc') return a.price - b.price;
      if (sortType === 'price-desc') return b.price - a.price;
      return 0; 
    });

  return (
    <div className="container"> 
      <h2>Featured Products</h2>

      <div style={{ display: 'flex', gap: '1rem', margin: '1rem 0' }}>
        <input 
          type="text"
          placeholder="Search vehicles..."
          value={searchTerm} 
          onChange={(e) => setSearchTerm(e.target.value)}
          style={{ flex: 1, padding: '0.5rem' }}
        />
 
        <select onChange={(e) => setSortType(e.target.value)} value={sortType}>
          <option value="">Sort</option>
          <option value="a-z">Name: A → Z</option>
          <option value="z-a">Name: Z → A</option>
          <option value="price-asc">Price: Low → High</option>
          <option value="price-desc">Price: High → Low</option> 
        </select>
      </div>

      <div className="product-grid">
        {filteredProducts.map(product => (
          <ProductCard key={product._id} product={product} />
        ))}
      </div> 
    </div>
  ); 
}