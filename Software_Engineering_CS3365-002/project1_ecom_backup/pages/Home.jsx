import React from 'react';
import products from '../data/products';
import ProductCard from '../components/ProductCard';

export default function Home() {
  return (
    <div className="container">
      <h2>Featured Products</h2>
      <div style={{
        display: 'flex',
        flexWrap: 'wrap',
        gap: '1rem',
        marginTop: '1rem'
      }}>
        {products.map(product => (
          <ProductCard key={product.id} product={product} />
        ))}
      </div>
    </div>
  );
}